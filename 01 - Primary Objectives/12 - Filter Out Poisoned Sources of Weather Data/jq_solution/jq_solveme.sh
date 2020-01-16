#!/bin/bash

jqFilter="jq_filter"

http_log="../http.log"

jq -r -f $jqFilter $http_log