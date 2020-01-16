typedef unsigned char   undefined;

typedef unsigned long long    GUID;
typedef unsigned int    ImageBaseOffset32;
typedef unsigned char    byte;
typedef unsigned int    dword;
typedef long long    longlong;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned short    ushort;
typedef short    wchar_t;
typedef unsigned short    word;
typedef union IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion;

typedef struct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct;

struct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct {
    dword OffsetToDirectory;
    dword DataIsDirectory;
};

union IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion {
    dword OffsetToData;
    struct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct;
};

typedef struct _SECURITY_ATTRIBUTES _SECURITY_ATTRIBUTES, *P_SECURITY_ATTRIBUTES;

typedef ulong DWORD;

typedef void * LPVOID;

typedef int BOOL;

struct _SECURITY_ATTRIBUTES {
    DWORD nLength;
    LPVOID lpSecurityDescriptor;
    BOOL bInheritHandle;
};

typedef union _union_518 _union_518, *P_union_518;

typedef struct _struct_519 _struct_519, *P_struct_519;

typedef void * PVOID;

struct _struct_519 {
    DWORD Offset;
    DWORD OffsetHigh;
};

union _union_518 {
    struct _struct_519 s;
    PVOID Pointer;
};

typedef struct _OVERLAPPED _OVERLAPPED, *P_OVERLAPPED;

typedef ulong ULONG_PTR;

typedef void * HANDLE;

struct _OVERLAPPED {
    ULONG_PTR Internal;
    ULONG_PTR InternalHigh;
    union _union_518 u;
    HANDLE hEvent;
};

typedef struct _OVERLAPPED * LPOVERLAPPED;

typedef long LONG;

typedef struct _EXCEPTION_POINTERS _EXCEPTION_POINTERS, *P_EXCEPTION_POINTERS;

typedef LONG (* PTOP_LEVEL_EXCEPTION_FILTER)(struct _EXCEPTION_POINTERS *);

typedef struct _EXCEPTION_RECORD _EXCEPTION_RECORD, *P_EXCEPTION_RECORD;

typedef struct _EXCEPTION_RECORD EXCEPTION_RECORD;

typedef EXCEPTION_RECORD * PEXCEPTION_RECORD;

typedef struct _CONTEXT _CONTEXT, *P_CONTEXT;

typedef struct _CONTEXT CONTEXT;

typedef CONTEXT * PCONTEXT;

typedef struct _FLOATING_SAVE_AREA _FLOATING_SAVE_AREA, *P_FLOATING_SAVE_AREA;

typedef struct _FLOATING_SAVE_AREA FLOATING_SAVE_AREA;

typedef uchar BYTE;

struct _FLOATING_SAVE_AREA {
    DWORD ControlWord;
    DWORD StatusWord;
    DWORD TagWord;
    DWORD ErrorOffset;
    DWORD ErrorSelector;
    DWORD DataOffset;
    DWORD DataSelector;
    BYTE RegisterArea[80];
    DWORD Cr0NpxState;
};

struct _CONTEXT {
    DWORD ContextFlags;
    DWORD Dr0;
    DWORD Dr1;
    DWORD Dr2;
    DWORD Dr3;
    DWORD Dr6;
    DWORD Dr7;
    FLOATING_SAVE_AREA FloatSave;
    DWORD SegGs;
    DWORD SegFs;
    DWORD SegEs;
    DWORD SegDs;
    DWORD Edi;
    DWORD Esi;
    DWORD Ebx;
    DWORD Edx;
    DWORD Ecx;
    DWORD Eax;
    DWORD Ebp;
    DWORD Eip;
    DWORD SegCs;
    DWORD EFlags;
    DWORD Esp;
    DWORD SegSs;
    BYTE ExtendedRegisters[512];
};

struct _EXCEPTION_RECORD {
    DWORD ExceptionCode;
    DWORD ExceptionFlags;
    struct _EXCEPTION_RECORD * ExceptionRecord;
    PVOID ExceptionAddress;
    DWORD NumberParameters;
    ULONG_PTR ExceptionInformation[15];
};

struct _EXCEPTION_POINTERS {
    PEXCEPTION_RECORD ExceptionRecord;
    PCONTEXT ContextRecord;
};

typedef struct _SECURITY_ATTRIBUTES * LPSECURITY_ATTRIBUTES;

typedef PTOP_LEVEL_EXCEPTION_FILTER LPTOP_LEVEL_EXCEPTION_FILTER;

typedef char CHAR;

typedef CHAR * LPCSTR;

typedef union _LARGE_INTEGER _LARGE_INTEGER, *P_LARGE_INTEGER;

typedef struct _struct_19 _struct_19, *P_struct_19;

typedef struct _struct_20 _struct_20, *P_struct_20;

typedef double LONGLONG;

struct _struct_20 {
    DWORD LowPart;
    LONG HighPart;
};

struct _struct_19 {
    DWORD LowPart;
    LONG HighPart;
};

union _LARGE_INTEGER {
    struct _struct_19 s;
    struct _struct_20 u;
    LONGLONG QuadPart;
};

typedef union _LARGE_INTEGER LARGE_INTEGER;

typedef struct _IMAGE_SECTION_HEADER _IMAGE_SECTION_HEADER, *P_IMAGE_SECTION_HEADER;

typedef union _union_226 _union_226, *P_union_226;

typedef ushort WORD;

union _union_226 {
    DWORD PhysicalAddress;
    DWORD VirtualSize;
};

struct _IMAGE_SECTION_HEADER {
    BYTE Name[8];
    union _union_226 Misc;
    DWORD VirtualAddress;
    DWORD SizeOfRawData;
    DWORD PointerToRawData;
    DWORD PointerToRelocations;
    DWORD PointerToLinenumbers;
    WORD NumberOfRelocations;
    WORD NumberOfLinenumbers;
    DWORD Characteristics;
};

typedef CHAR * LPSTR;

typedef struct _IMAGE_SECTION_HEADER * PIMAGE_SECTION_HEADER;

typedef struct IMAGE_DOS_HEADER IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;

struct IMAGE_DOS_HEADER {
    char e_magic[2]; // Magic number
    word e_cblp; // Bytes of last page
    word e_cp; // Pages in file
    word e_crlc; // Relocations
    word e_cparhdr; // Size of header in paragraphs
    word e_minalloc; // Minimum extra paragraphs needed
    word e_maxalloc; // Maximum extra paragraphs needed
    word e_ss; // Initial (relative) SS value
    word e_sp; // Initial SP value
    word e_csum; // Checksum
    word e_ip; // Initial IP value
    word e_cs; // Initial (relative) CS value
    word e_lfarlc; // File address of relocation table
    word e_ovno; // Overlay number
    word e_res[4][4]; // Reserved words
    word e_oemid; // OEM identifier (for e_oeminfo)
    word e_oeminfo; // OEM information; e_oemid specific
    word e_res2[10][10]; // Reserved words
    dword e_lfanew; // File address of new exe header
    byte e_program[64]; // Actual DOS program
};

typedef ULONG_PTR HCRYPTKEY;

typedef ULONG_PTR HCRYPTPROV;

typedef ULONG_PTR HCRYPTHASH;

typedef ULONG_PTR DWORD_PTR;

typedef struct DotNetPdbInfo DotNetPdbInfo, *PDotNetPdbInfo;

struct DotNetPdbInfo {
    char signature[4];
    GUID guid;
    dword age;
    char pdbname[65];
};

typedef struct _FILETIME _FILETIME, *P_FILETIME;

typedef struct _FILETIME * LPFILETIME;

struct _FILETIME {
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
};

typedef struct HINSTANCE__ HINSTANCE__, *PHINSTANCE__;

typedef struct HINSTANCE__ * HINSTANCE;

struct HINSTANCE__ {
    int unused;
};

typedef void * LPCVOID;

typedef HINSTANCE HMODULE;

typedef DWORD * LPDWORD;

typedef uint UINT;

typedef BYTE * PBYTE;

typedef struct IMAGE_OPTIONAL_HEADER32 IMAGE_OPTIONAL_HEADER32, *PIMAGE_OPTIONAL_HEADER32;

typedef struct IMAGE_DATA_DIRECTORY IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;

struct IMAGE_DATA_DIRECTORY {
    ImageBaseOffset32 VirtualAddress;
    dword Size;
};

struct IMAGE_OPTIONAL_HEADER32 {
    word Magic;
    byte MajorLinkerVersion;
    byte MinorLinkerVersion;
    dword SizeOfCode;
    dword SizeOfInitializedData;
    dword SizeOfUninitializedData;
    ImageBaseOffset32 AddressOfEntryPoint;
    ImageBaseOffset32 BaseOfCode;
    ImageBaseOffset32 BaseOfData;
    pointer32 ImageBase;
    dword SectionAlignment;
    dword FileAlignment;
    word MajorOperatingSystemVersion;
    word MinorOperatingSystemVersion;
    word MajorImageVersion;
    word MinorImageVersion;
    word MajorSubsystemVersion;
    word MinorSubsystemVersion;
    dword Win32VersionValue;
    dword SizeOfImage;
    dword SizeOfHeaders;
    dword CheckSum;
    word Subsystem;
    word DllCharacteristics;
    dword SizeOfStackReserve;
    dword SizeOfStackCommit;
    dword SizeOfHeapReserve;
    dword SizeOfHeapCommit;
    dword LoaderFlags;
    dword NumberOfRvaAndSizes;
    struct IMAGE_DATA_DIRECTORY DataDirectory[16];
};

typedef struct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct;

struct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct {
    dword NameOffset;
    dword NameIsString;
};

typedef struct IMAGE_DEBUG_DIRECTORY IMAGE_DEBUG_DIRECTORY, *PIMAGE_DEBUG_DIRECTORY;

struct IMAGE_DEBUG_DIRECTORY {
    dword Characteristics;
    dword TimeDateStamp;
    word MajorVersion;
    word MinorVersion;
    dword Type;
    dword SizeOfData;
    dword AddressOfRawData;
    dword PointerToRawData;
};

typedef struct IMAGE_FILE_HEADER IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;

struct IMAGE_FILE_HEADER {
    word Machine; // 332
    word NumberOfSections;
    dword TimeDateStamp;
    dword PointerToSymbolTable;
    dword NumberOfSymbols;
    word SizeOfOptionalHeader;
    word Characteristics;
};

typedef struct IMAGE_NT_HEADERS32 IMAGE_NT_HEADERS32, *PIMAGE_NT_HEADERS32;

struct IMAGE_NT_HEADERS32 {
    char Signature[4];
    struct IMAGE_FILE_HEADER FileHeader;
    struct IMAGE_OPTIONAL_HEADER32 OptionalHeader;
};

typedef union IMAGE_RESOURCE_DIRECTORY_ENTRY IMAGE_RESOURCE_DIRECTORY_ENTRY, *PIMAGE_RESOURCE_DIRECTORY_ENTRY;

typedef union IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion;

union IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion {
    struct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct;
    dword Name;
    word Id;
};

union IMAGE_RESOURCE_DIRECTORY_ENTRY {
    union IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion NameUnion;
    union IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion DirectoryUnion;
};

typedef struct IMAGE_SECTION_HEADER IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;

typedef union Misc Misc, *PMisc;

typedef enum SectionFlags {
    IMAGE_SCN_ALIGN_1024BYTES=11534336,
    IMAGE_SCN_ALIGN_128BYTES=8388608,
    IMAGE_SCN_ALIGN_16BYTES=5242880,
    IMAGE_SCN_ALIGN_1BYTES=1048576,
    IMAGE_SCN_ALIGN_2048BYTES=12582912,
    IMAGE_SCN_ALIGN_256BYTES=9437184,
    IMAGE_SCN_ALIGN_2BYTES=2097152,
    IMAGE_SCN_ALIGN_32BYTES=6291456,
    IMAGE_SCN_ALIGN_4096BYTES=13631488,
    IMAGE_SCN_ALIGN_4BYTES=3145728,
    IMAGE_SCN_ALIGN_512BYTES=10485760,
    IMAGE_SCN_ALIGN_64BYTES=7340032,
    IMAGE_SCN_ALIGN_8192BYTES=14680064,
    IMAGE_SCN_ALIGN_8BYTES=4194304,
    IMAGE_SCN_CNT_CODE=32,
    IMAGE_SCN_CNT_INITIALIZED_DATA=64,
    IMAGE_SCN_CNT_UNINITIALIZED_DATA=128,
    IMAGE_SCN_GPREL=32768,
    IMAGE_SCN_LNK_COMDAT=4096,
    IMAGE_SCN_LNK_INFO=512,
    IMAGE_SCN_LNK_NRELOC_OVFL=16777216,
    IMAGE_SCN_LNK_OTHER=256,
    IMAGE_SCN_LNK_REMOVE=2048,
    IMAGE_SCN_MEM_16BIT=131072,
    IMAGE_SCN_MEM_DISCARDABLE=33554432,
    IMAGE_SCN_MEM_EXECUTE=536870912,
    IMAGE_SCN_MEM_LOCKED=262144,
    IMAGE_SCN_MEM_NOT_CACHED=67108864,
    IMAGE_SCN_MEM_NOT_PAGED=134217728,
    IMAGE_SCN_MEM_PRELOAD=524288,
    IMAGE_SCN_MEM_PURGEABLE=131072,
    IMAGE_SCN_MEM_READ=1073741824,
    IMAGE_SCN_MEM_SHARED=268435456,
    IMAGE_SCN_MEM_WRITE=2147483648,
    IMAGE_SCN_RESERVED_0001=16,
    IMAGE_SCN_RESERVED_0040=1024,
    IMAGE_SCN_TYPE_NO_PAD=8
} SectionFlags;

union Misc {
    dword PhysicalAddress;
    dword VirtualSize;
};

struct IMAGE_SECTION_HEADER {
    char Name[8];
    union Misc Misc;
    ImageBaseOffset32 VirtualAddress;
    dword SizeOfRawData;
    dword PointerToRawData;
    dword PointerToRelocations;
    dword PointerToLinenumbers;
    word NumberOfRelocations;
    word NumberOfLinenumbers;
    enum SectionFlags Characteristics;
};

typedef struct IMAGE_RESOURCE_DATA_ENTRY IMAGE_RESOURCE_DATA_ENTRY, *PIMAGE_RESOURCE_DATA_ENTRY;

struct IMAGE_RESOURCE_DATA_ENTRY {
    dword OffsetToData;
    dword Size;
    dword CodePage;
    dword Reserved;
};

typedef struct IMAGE_RESOURCE_DIRECTORY IMAGE_RESOURCE_DIRECTORY, *PIMAGE_RESOURCE_DIRECTORY;

struct IMAGE_RESOURCE_DIRECTORY {
    dword Characteristics;
    dword TimeDateStamp;
    word MajorVersion;
    word MinorVersion;
    word NumberOfNamedEntries;
    word NumberOfIdEntries;
};

typedef struct IMAGE_LOAD_CONFIG_DIRECTORY32 IMAGE_LOAD_CONFIG_DIRECTORY32, *PIMAGE_LOAD_CONFIG_DIRECTORY32;

struct IMAGE_LOAD_CONFIG_DIRECTORY32 {
    dword Size;
    dword TimeDateStamp;
    word MajorVersion;
    word MinorVersion;
    dword GlobalFlagsClear;
    dword GlobalFlagsSet;
    dword CriticalSectionDefaultTimeout;
    dword DeCommitFreeBlockThreshold;
    dword DeCommitTotalFreeThreshold;
    pointer32 LockPrefixTable;
    dword MaximumAllocationSize;
    dword VirtualMemoryThreshold;
    dword ProcessHeapFlags;
    dword ProcessAffinityMask;
    word CsdVersion;
    word DependentLoadFlags;
    pointer32 EditList;
    pointer32 SecurityCookie;
    pointer32 SEHandlerTable;
    dword SEHandlerCount;
};

typedef struct _iobuf _iobuf, *P_iobuf;

struct _iobuf {
    char * _ptr;
    int _cnt;
    char * _base;
    int _flag;
    int _file;
    int _charbuf;
    int _bufsiz;
    char * _tmpfname;
};

typedef struct _iobuf FILE;

typedef char * va_list;

typedef uint uintptr_t;

typedef int (* _onexit_t)(void);

typedef struct _startupinfo _startupinfo, *P_startupinfo;

struct _startupinfo {
    int newmode;
};

typedef longlong __time64_t;

typedef uint size_t;

typedef int errno_t;




// WARNING: Globals starting with '_' overlap smaller symbols at the same address

int __cdecl
FUN_00401000(int param_1,undefined4 *param_2,char *param_3,int param_4,int *param_5,int param_6)

{
  int *piVar1;
  char cVar2;
  char *_Format;
  int iVar3;
  int iVar4;
  FILE *pFVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  char *local_40;
  int local_38;
  uint local_30;
  int local_2c;
  int local_28;
  int local_20;
  int local_18;
  int local_14;
  char local_d;
  uint local_c;
  char local_5;
  
  local_c = 0;
  _Format = getenv("POSIXLY_CORRECT");
  iVar3 = DAT_00406000;
  if (_Format == (char *)0x0) {
    local_5 = *param_3;
    local_c = (uint)(local_5 == ':');
    local_d = param_3[local_c];
    if ((((local_d == '+') || (uVar6 = local_c, local_d == '-')) &&
        (uVar6 = local_c + 1, local_5 != ':')) && (local_5 = param_3[uVar6], local_5 == ':')) {
      uVar6 = local_c + 2;
    }
  }
  else {
    local_d = '+';
    local_5 = '+';
    uVar6 = local_c;
  }
  local_c = uVar6;
  DAT_00406024 = 0;
  if ((DAT_00406000 < param_1) &&
     (((*(char *)param_2[DAT_00406000] != '-' || (*(char *)(param_2[DAT_00406000] + 1) != '-')) ||
      (*(char *)(param_2[DAT_00406000] + 2) != '\0')))) {
    if ((*(char *)param_2[DAT_00406000] == '-') && (*(char *)(param_2[DAT_00406000] + 1) != '\0')) {
      if ((param_6 == 0) && (*(char *)(param_2[DAT_00406000] + 1) != '-')) {
        local_14 = FUN_00401770(param_1,param_2,param_3);
      }
      else {
        local_2c = 0;
        local_28 = 0;
        DAT_00406020 = (int)*(char *)(param_2[DAT_00406000] + 1);
        if ((DAT_00406020 != 0x2d) && (*(char *)(param_2[DAT_00406000] + 2) == '\0')) {
          local_30 = local_c;
          while( true ) {
            iVar3 = (int)param_3[local_30];
            uVar6 = local_30 + 1;
            if (iVar3 == 0) break;
            if (((param_3[uVar6] == ':') || ((iVar3 == 0x57 && (param_3[uVar6] == ';')))) &&
               (uVar6 = local_30 + 2, param_3[local_30 + 2] == ':')) {
              uVar6 = local_30 + 3;
            }
            local_30 = uVar6;
            if (DAT_00406020 == iVar3) {
              iVar3 = FUN_00401770(param_1,param_2,param_3);
              return iVar3;
            }
          }
        }
        iVar3 = 2 - (uint)(*(char *)(param_2[DAT_00406000] + 1) != '-');
        local_38 = iVar3;
        while ((*(char *)(param_2[DAT_00406000] + local_38) != '\0' &&
               (*(char *)(param_2[DAT_00406000] + local_38) != '='))) {
          local_38 = local_38 + 1;
        }
        local_30 = 0;
        while ((*(int *)(param_4 + local_30 * 0x10) != 0 && (local_28 == 0))) {
          local_40 = *(char **)(param_4 + local_30 * 0x10);
          _Format = local_40 + 1;
          do {
            cVar2 = *local_40;
            local_40 = local_40 + 1;
          } while (cVar2 != '\0');
          if ((local_40 + -(int)_Format == (char *)(local_38 - iVar3)) &&
             (iVar4 = strncmp(*(char **)(param_4 + local_30 * 0x10),
                              (char *)(param_2[DAT_00406000] + iVar3),local_38 - iVar3), iVar4 == 0)
             ) {
            local_2c = local_30;
            local_28 = 1;
          }
          local_30 = local_30 + 1;
        }
        if (local_28 == 0) {
          local_30 = 0;
          while (*(int *)(param_4 + local_30 * 0x10) != 0) {
            iVar4 = strncmp(*(char **)(param_4 + local_30 * 0x10),
                            (char *)(param_2[DAT_00406000] + iVar3),local_38 - iVar3);
            if (iVar4 == 0) {
              local_2c = local_30;
              local_28 = local_28 + 1;
            }
            local_30 = local_30 + 1;
          }
        }
        if (local_28 == 1) {
          local_14 = 0;
          if (*(char *)(param_2[DAT_00406000] + local_38) == '=') {
            if (*(int *)(param_4 + 4 + local_2c * 0x10) == 0) {
              local_14 = 0x3f;
              if (_DAT_00406004 != 0) {
                uVar8 = *(undefined4 *)(param_4 + local_2c * 0x10);
                uVar7 = *param_2;
                _Format = "%s: option `--%s\' doesn\'t allow an argument\n";
                pFVar5 = __iob_func();
                fprintf(pFVar5 + 2,_Format,uVar7,uVar8);
              }
            }
            else {
              DAT_00406024 = param_2[DAT_00406000] + local_38 + 1;
            }
          }
          else {
            if (*(int *)(param_4 + 4 + local_2c * 0x10) == 1) {
              DAT_00406000 = DAT_00406000 + 1;
              if (DAT_00406000 < param_1) {
                DAT_00406024 = param_2[DAT_00406000];
              }
              else {
                local_14 = (int)(char)((-(local_5 != ':') & 5U) + 0x3a);
                if (_DAT_00406004 != 0) {
                  uVar8 = *(undefined4 *)(param_4 + local_2c * 0x10);
                  uVar7 = *param_2;
                  _Format = "%s: option `--%s\' requires an argument\n";
                  pFVar5 = __iob_func();
                  fprintf(pFVar5 + 2,_Format,uVar7,uVar8);
                }
              }
            }
          }
          if (local_14 == 0) {
            if (param_5 != (int *)0x0) {
              *param_5 = local_2c;
            }
            if (*(int *)(param_4 + 8 + local_2c * 0x10) == 0) {
              local_14 = *(int *)(param_4 + 0xc + local_2c * 0x10);
            }
            else {
              **(undefined4 **)(param_4 + 8 + local_2c * 0x10) =
                   *(undefined4 *)(param_4 + 0xc + local_2c * 0x10);
            }
          }
          DAT_00406000 = DAT_00406000 + 1;
        }
        else {
          if (local_28 == 0) {
            if (iVar3 == 1) {
              local_14 = FUN_00401770(param_1,param_2,param_3);
            }
            else {
              local_14 = 0x3f;
              if (_DAT_00406004 != 0) {
                uVar8 = param_2[DAT_00406000];
                DAT_00406000 = DAT_00406000 + 1;
                uVar7 = *param_2;
                _Format = "%s: unrecognized option `%s\'\n";
                pFVar5 = __iob_func();
                fprintf(pFVar5 + 2,_Format,uVar7,uVar8);
              }
            }
          }
          else {
            local_14 = 0x3f;
            if (_DAT_00406004 != 0) {
              uVar8 = param_2[DAT_00406000];
              DAT_00406000 = DAT_00406000 + 1;
              uVar7 = *param_2;
              _Format = "%s: option `%s\' is ambiguous\n";
              pFVar5 = __iob_func();
              fprintf(pFVar5 + 2,_Format,uVar7,uVar8);
            }
          }
        }
      }
    }
    else {
      local_14 = -1;
      if (local_d == '+') {
        DAT_00406024 = 0;
        return -1;
      }
      if (local_d == '-') {
        piVar1 = param_2 + DAT_00406000;
        DAT_00406000 = DAT_00406000 + 1;
        DAT_00406024 = *piVar1;
        return 1;
      }
      local_18 = DAT_00406000;
      while (local_18 < param_1) {
        if ((*(char *)param_2[local_18] == '-') && (*(char *)(param_2[local_18] + 1) != '\0')) {
          DAT_00406000 = local_18;
          local_14 = FUN_00401000(param_1,param_2,param_3,param_4,param_5,param_6);
          while (iVar3 < local_18) {
            local_18 = local_18 + -1;
            uVar8 = param_2[local_18];
            local_20 = local_18;
            while (local_20 + 1 < DAT_00406000) {
              param_2[local_20] = param_2[local_20 + 1];
              local_20 = local_20 + 1;
            }
            DAT_00406000 = DAT_00406000 + -1;
            param_2[DAT_00406000] = uVar8;
          }
          break;
        }
        local_18 = local_18 + 1;
      }
    }
  }
  else {
    DAT_00406000 = DAT_00406000 + 1;
    local_14 = -1;
  }
  if (param_1 < DAT_00406000) {
    DAT_00406000 = param_1;
  }
  return local_14;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

int __cdecl FUN_00401770(int param_1,undefined4 *param_2,char *param_3)

{
  char *_Format;
  uint uVar1;
  FILE *pFVar2;
  int iVar3;
  undefined4 uVar4;
  int local_20;
  int local_18;
  uint local_14;
  int local_10;
  char *local_c;
  char local_6;
  char local_5;
  
  local_14 = 0;
  local_10 = -1;
  _Format = getenv("POSIXLY_CORRECT");
  iVar3 = DAT_00406000;
  if (_Format == (char *)0x0) {
    local_5 = *param_3;
    local_14 = (uint)(local_5 == ':');
    local_6 = param_3[local_14];
    if ((((local_6 == '+') || (uVar1 = local_14, local_6 == '-')) &&
        (uVar1 = local_14 + 1, local_5 != ':')) && (local_5 = param_3[uVar1], local_5 == ':')) {
      uVar1 = local_14 + 2;
    }
  }
  else {
    local_6 = '+';
    local_5 = '+';
    uVar1 = local_14;
  }
  local_14 = uVar1;
  DAT_00406024 = 0;
  if (DAT_00406028 == 0) {
    if ((DAT_00406000 < param_1) &&
       (((*(char *)param_2[DAT_00406000] != '-' || (*(char *)(param_2[DAT_00406000] + 1) != '-')) ||
        (*(char *)(param_2[DAT_00406000] + 2) != '\0')))) {
      if ((*(char *)param_2[DAT_00406000] == '-') && (*(char *)(param_2[DAT_00406000] + 1) != '\0'))
      {
        DAT_00406028 = 1;
        local_10 = FUN_00401770(param_1,param_2,param_3);
      }
      else {
        if (local_6 == '+') {
          local_10 = -1;
        }
        else {
          if (local_6 != '-') {
            local_18 = DAT_00406000;
            while( true ) {
              if (param_1 <= local_18) goto LAB_00401c30;
              if ((*(char *)param_2[local_18] == '-') && (*(char *)(param_2[local_18] + 1) != '\0'))
              break;
              local_18 = local_18 + 1;
            }
            DAT_00406000 = local_18;
            local_10 = FUN_00401770(param_1,param_2,param_3);
            while (iVar3 < local_18) {
              local_18 = local_18 + -1;
              uVar4 = param_2[local_18];
              local_20 = local_18;
              while (local_20 + 1 < DAT_00406000) {
                param_2[local_20] = param_2[local_20 + 1];
                local_20 = local_20 + 1;
              }
              DAT_00406000 = DAT_00406000 + -1;
              param_2[DAT_00406000] = uVar4;
            }
LAB_00401c30:
            if (local_18 == param_1) {
              local_10 = -1;
            }
            goto LAB_00401c65;
          }
          DAT_00406024 = param_2[DAT_00406000];
          DAT_00406000 = DAT_00406000 + 1;
          DAT_00406028 = 0;
          local_10 = 1;
        }
      }
    }
    else {
      DAT_00406000 = DAT_00406000 + 1;
      local_10 = -1;
    }
  }
  else {
    DAT_00406020 = (int)*(char *)(param_2[DAT_00406000] + DAT_00406028);
    local_c = param_3 + local_14;
    while (*local_c != '\0') {
      if (DAT_00406020 == (int)*local_c) {
        DAT_00406028 = DAT_00406028 + 1;
        local_10 = DAT_00406020;
        if ((local_c[1] == ':') || ((DAT_00406020 == 0x57 && (local_c[1] == ';')))) {
          if (*(char *)(param_2[DAT_00406000] + DAT_00406028) == '\0') {
            if (local_c[2] != ':') {
              DAT_00406028 = 0;
              iVar3 = DAT_00406000 + 1;
              if (iVar3 < param_1) {
                DAT_00406024 = param_2[iVar3];
                DAT_00406000 = DAT_00406000 + 2;
              }
              else {
                DAT_00406000 = iVar3;
                if (_DAT_00406004 != 0) {
                  uVar4 = *param_2;
                  _Format = "%s: option requires an argument -- %c\n";
                  iVar3 = DAT_00406020;
                  pFVar2 = __iob_func();
                  fprintf(pFVar2 + 2,_Format,uVar4,iVar3);
                }
                local_10 = (int)(char)((-(local_5 != ':') & 5U) + 0x3a);
              }
            }
          }
          else {
            DAT_00406024 = param_2[DAT_00406000] + DAT_00406028;
            DAT_00406000 = DAT_00406000 + 1;
            DAT_00406028 = 0;
          }
        }
        goto LAB_00401a2b;
      }
      local_c = local_c + 1;
    }
    if (_DAT_00406004 != 0) {
      uVar4 = *param_2;
      _Format = "%s: illegal option -- %c\n";
      iVar3 = DAT_00406020;
      pFVar2 = __iob_func();
      fprintf(pFVar2 + 2,_Format,uVar4,iVar3);
    }
    local_10 = 0x3f;
    DAT_00406028 = DAT_00406028 + 1;
    if (*(char *)(param_2[DAT_00406000] + DAT_00406028) == '\0') {
      DAT_00406000 = DAT_00406000 + 1;
      DAT_00406028 = 0;
    }
LAB_00401a2b:
    if ((DAT_00406028 != 0) && (*(char *)(param_2[DAT_00406000] + DAT_00406028) == '\0')) {
      DAT_00406000 = DAT_00406000 + 1;
      DAT_00406028 = 0;
    }
  }
LAB_00401c65:
  if (param_1 < DAT_00406000) {
    DAT_00406000 = param_1;
  }
  return local_10;
}



void __cdecl FUN_00401c90(int param_1,undefined4 *param_2,char *param_3,int param_4,int *param_5)

{
  FUN_00401000(param_1,param_2,param_3,param_4,param_5,1);
  return;
}



void FUN_00401cc0(undefined4 param_1)

{
  DWORD dwMessageId;
  HMODULE lpSource;
  FILE *pFVar1;
  DWORD dwLanguageId;
  DWORD nSize;
  va_list *Arguments;
  char *_Format;
  char **lpBuffer;
  char *local_10;
  char *local_c;
  DWORD local_8;
  
  local_c = (char *)0x0;
  dwMessageId = GetLastError();
  Arguments = (va_list *)0x0;
  nSize = 0;
  lpBuffer = &local_c;
  dwLanguageId = 0x400;
  local_8 = dwMessageId;
  lpSource = GetModuleHandleA("wininet.dll");
  FormatMessageA(0x1b00,lpSource,dwMessageId,dwLanguageId,(LPSTR)lpBuffer,nSize,Arguments);
  _Format = "Uh oh, something went very wrong. That\'s not supposed to happen.\n";
  pFVar1 = __iob_func();
  fprintf(pFVar1 + 2,_Format);
  _Format = "Please don\'t tell Santa :(\n";
  pFVar1 = __iob_func();
  fprintf(pFVar1 + 2,_Format);
  lpBuffer = &_Format_004042c4;
  pFVar1 = __iob_func();
  fprintf(pFVar1 + 2,(char *)lpBuffer);
  if (local_c == (char *)0x0) {
    local_10 = "(unknown error)";
  }
  else {
    local_10 = local_c;
  }
  _Format = "%s: %s (%d)\n";
  dwMessageId = local_8;
  pFVar1 = __iob_func();
  fprintf(pFVar1 + 2,_Format,param_1,local_10,dwMessageId);
                    // WARNING: Subroutine does not return
  exit(1);
}



void __cdecl FUN_00401d90(undefined4 param_1)

{
  FILE *pFVar1;
  char *_Format;
  undefined4 uVar2;
  
  _Format = "Seed = %d\n\n";
  uVar2 = param_1;
  pFVar1 = __iob_func();
  fprintf(pFVar1 + 2,_Format,uVar2);
  DAT_0040602c = param_1;
  return;
}



uint FUN_00401dc0(void)

{
  DAT_0040602c = DAT_0040602c * 0x343fd + 0x269ec3;
  return DAT_0040602c >> 0x10 & 0x7fff;
}



void __cdecl FUN_00401df0(int param_1)

{
  FILE *pFVar1;
  uint uVar2;
  __time64_t _Var3;
  char *_Format;
  uint local_8;
  
  _Format = "Our miniature elves are putting together random bits for your secret key!\n\n";
  pFVar1 = __iob_func();
  fprintf(pFVar1 + 2,_Format);
  _Var3 = FUN_00401e60((__time64_t *)0x0);
  FUN_00401d90((int)_Var3);
  local_8 = 0;
  while (local_8 < 8) {
    uVar2 = FUN_00401dc0();
    *(undefined *)(param_1 + local_8) = (char)uVar2;
    local_8 = local_8 + 1;
  }
  return;
}



__time64_t __cdecl FUN_00401e60(__time64_t *param_1)

{
  __time64_t _Var1;
  
  _Var1 = _time64(param_1);
  return _Var1;
}



void __cdecl FUN_00401e80(int param_1,int param_2)

{
  uint local_8;
  
  local_8 = 0;
  while (local_8 < 8) {
    sprintf((char *)(param_2 + local_8 * 2),(char *)&_Format_0040435c,
            (uint)*(byte *)(param_1 + local_8));
    local_8 = local_8 + 1;
  }
  return;
}



void __cdecl FUN_00401ed0(int param_1,int param_2)

{
  long lVar1;
  undefined2 local_c;
  undefined local_a;
  uint local_8;
  
  local_a = 0;
  local_8 = 0;
  while (local_8 < 8) {
    local_c = *(undefined2 *)(param_1 + local_8 * 2);
    lVar1 = strtol((char *)&local_c,(char **)0x0,0x10);
    *(undefined *)(param_2 + local_8) = (char)lVar1;
    local_8 = local_8 + 1;
  }
  return;
}



void __cdecl FUN_00401f20(int param_1,int param_2)

{
  byte bVar1;
  FILE *pFVar2;
  int iVar3;
  bool bVar4;
  byte *pbVar5;
  undefined *puVar6;
  char *pcVar7;
  char *_Format;
  char **_Format_00;
  int local_454;
  byte *local_44c;
  byte *local_448;
  undefined local_444 [1028];
  int local_40;
  int local_3c;
  byte local_38 [12];
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  undefined local_1c [20];
  uint local_8;
  
  local_8 = DAT_00406008 ^ (uint)&stack0xfffffffc;
  _Format = "Elfscrowing your key...\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format_00 = &_Format_00404364;
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,(char *)_Format_00);
  FUN_00401e80(param_2,(int)local_1c);
  local_40 = InternetOpenA("ElfScrow V1.01 (SantaBrowse Compatible)",1,0,0,0);
  if (local_40 == 0) {
    FUN_00401cc0("InternetOpen failed");
  }
  local_3c = InternetConnectA(local_40,"elfscrow.elfu.org",
                              (-(uint)(param_1 != 0) & 0xfffffe95) + 0x1bb,&DAT_004042c3,
                              &DAT_004042c2,3,0,0);
  if (local_3c == 0) {
    FUN_00401cc0("InternetConnect failed");
  }
  local_20 = HttpOpenRequestA(local_3c,&DAT_004043dc,"/api/store",0,0,0,
                              (-(uint)(param_1 != 0) & 0xff800000) + 0x800000,0);
  if (local_20 == 0) {
    FUN_00401cc0("HttpOpenRequest failed");
  }
  local_28 = 0x80;
  iVar3 = InternetSetOptionA(local_20,0x1f,&local_28,4);
  if (iVar3 == 0) {
    FUN_00401cc0("InternetSetOption failed");
  }
  pcVar7 = "elfscrow.elfu.org/api/store";
  _Format = "Elfscrowing the key to: %s\n\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format,pcVar7);
  iVar3 = HttpSendRequestA(local_20,0,0,local_1c,0x10);
  if (iVar3 == 0) {
    FUN_00401cc0("HttpSendRequest failed");
  }
  local_24 = 10;
  iVar3 = HttpQueryInfoA(local_20,0x13,local_38,&local_24,0);
  if (iVar3 == 0) {
    FUN_00401cc0("HttpQueryInfo failed");
  }
  iVar3 = InternetReadFile(local_20,local_444,0x3ff,&local_2c);
  if (iVar3 == 0) {
    FUN_00401cc0("HTTP request failed");
  }
  local_444[local_2c] = 0;
  local_448 = &DAT_00404498;
  local_44c = local_38;
  do {
    bVar1 = *local_44c;
    bVar4 = bVar1 < *local_448;
    if (bVar1 != *local_448) {
LAB_0040216c:
      local_454 = (1 - (uint)bVar4) - (uint)(bVar4 != false);
      goto LAB_00402177;
    }
    if (bVar1 == 0) break;
    bVar1 = local_44c[1];
    bVar4 = bVar1 < local_448[1];
    if (bVar1 != local_448[1]) goto LAB_0040216c;
    local_44c = local_44c + 2;
    local_448 = local_448 + 2;
  } while (bVar1 != 0);
  local_454 = 0;
LAB_00402177:
  if (local_454 == 0) {
    puVar6 = local_444;
    _Format = "Your secret id is %s - Santa Says, don\'t share that key with anybody!\n";
    pFVar2 = __iob_func();
    fprintf(pFVar2 + 2,_Format,puVar6);
    FUN_00403546();
    return;
  }
  _Format = "Uh oh, an error happened! Please don\'t tell Santa :(\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format_00 = &_Format_0040449c;
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,(char *)_Format_00);
  puVar6 = local_444;
  pbVar5 = local_38;
  _Format = "HTTP %s: %s\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format,pbVar5,puVar6);
                    // WARNING: Subroutine does not return
  exit(1);
}



void __cdecl FUN_00402220(int param_1,int param_2,char *param_3)

{
  char cVar1;
  byte bVar2;
  FILE *pFVar3;
  int iVar4;
  bool bVar5;
  byte *pbVar6;
  undefined *puVar7;
  char *pcVar8;
  char *_Format;
  char **_Format_00;
  int local_44c;
  byte *local_444;
  byte *local_440;
  char *local_430;
  undefined local_42c [1028];
  int local_28;
  int local_24;
  byte local_20 [12];
  uint local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  local_14 = DAT_00406008 ^ (uint)&stack0xfffffffc;
  _Format = "Let\'s see if we can find your key...\n";
  pFVar3 = __iob_func();
  fprintf(pFVar3 + 2,_Format);
  _Format_00 = &_Format_00404558;
  pFVar3 = __iob_func();
  fprintf(pFVar3 + 2,(char *)_Format_00);
  local_28 = InternetOpenA("Elfscrow 1.0 (SantaBrowse Compatible)",1,0,0,0);
  if (local_28 == 0) {
    FUN_00401cc0("InternetOpen failed");
  }
  local_24 = InternetConnectA(local_28,"elfscrow.elfu.org",
                              (-(uint)(param_1 != 0) & 0xfffffe95) + 0x1bb,0x4042c7,0x4042c6,3,0,0);
  if (local_24 == 0) {
    FUN_00401cc0("InternetConnect failed");
  }
  local_8 = HttpOpenRequestA(local_24,&DAT_004045d4,"/api/retrieve",0,0,0,
                             (-(uint)(param_1 != 0) & 0xff800000) + 0x800000,0);
  if (local_8 == 0) {
    FUN_00401cc0("HttpOpenRequest failed");
  }
  pcVar8 = "/api/retrieve";
  _Format = "Retrieving the key from: %s\n\n";
  pFVar3 = __iob_func();
  fprintf(pFVar3 + 2,_Format,pcVar8);
  local_430 = param_3;
  do {
    cVar1 = *local_430;
    local_430 = local_430 + 1;
  } while (cVar1 != '\0');
  iVar4 = HttpSendRequestA(local_8,0,0,param_3,local_430 + -(int)(param_3 + 1));
  if (iVar4 == 0) {
    FUN_00401cc0("HttpSendRequest failed");
  }
  local_c = 10;
  iVar4 = HttpQueryInfoA(local_8,0x13,local_20,&local_c,0);
  if (iVar4 == 0) {
    FUN_00401cc0("HttpQueryInfo failed");
  }
  iVar4 = InternetReadFile(local_8,local_42c,0x400,&local_10);
  if (iVar4 == 0) {
    FUN_00401cc0("HTTP request failed");
  }
  local_42c[local_10] = 0;
  local_440 = &DAT_00404668;
  local_444 = local_20;
  do {
    bVar2 = *local_444;
    bVar5 = bVar2 < *local_440;
    if (bVar2 != *local_440) {
LAB_0040247d:
      local_44c = (1 - (uint)bVar5) - (uint)(bVar5 != false);
      goto LAB_00402488;
    }
    if (bVar2 == 0) break;
    bVar2 = local_444[1];
    bVar5 = bVar2 < local_440[1];
    if (bVar2 != local_440[1]) goto LAB_0040247d;
    local_444 = local_444 + 2;
    local_440 = local_440 + 2;
  } while (bVar2 != 0);
  local_44c = 0;
LAB_00402488:
  if (local_44c == 0) {
    puVar7 = local_42c;
    _Format = "We found your key!\n";
    pFVar3 = __iob_func();
    fprintf(pFVar3 + 2,_Format,puVar7);
    FUN_00401ed0((int)local_42c,param_2);
    FUN_00403546();
    return;
  }
  _Format = "Uh oh, an error happened! Please don\'t tell Santa :(\n";
  pFVar3 = __iob_func();
  fprintf(pFVar3 + 2,_Format);
  _Format_00 = &_Format_004046b8;
  pFVar3 = __iob_func();
  fprintf(pFVar3 + 2,(char *)_Format_00);
  puVar7 = local_42c;
  pbVar6 = local_20;
  _Format = "HTTP %s: %s\n";
  pFVar3 = __iob_func();
  fprintf(pFVar3 + 2,_Format,pbVar6,puVar7);
                    // WARNING: Subroutine does not return
  exit(1);
}



void __cdecl FUN_00402540(undefined4 param_1,int param_2,uint param_3)

{
  FILE *pFVar1;
  uint uVar2;
  char **_Format;
  char *_Format_00;
  uint local_8;
  
  _Format = &_Format_004046cc;
  pFVar1 = __iob_func();
  fprintf(pFVar1 + 2,(char *)_Format,param_1);
  local_8 = 0;
  while (local_8 < param_3) {
    uVar2 = (uint)*(byte *)(param_2 + local_8);
    _Format = &_Format_004046d4;
    pFVar1 = __iob_func();
    fprintf(pFVar1 + 2,(char *)_Format,uVar2);
    local_8 = local_8 + 1;
  }
  _Format_00 = " (length: %d)\n\n";
  pFVar1 = __iob_func();
  fprintf(pFVar1 + 2,_Format_00,param_3);
  return;
}



void * __cdecl FUN_004025c0(LPCSTR param_1,LPDWORD param_2)

{
  DWORD _Size;
  void *lpBuffer;
  BOOL BVar1;
  HANDLE local_c;
  
  if (param_1 == (LPCSTR)0x0) {
    local_c = GetStdHandle(0xfffffff6);
  }
  else {
    local_c = CreateFileA(param_1,0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
    if (local_c == (HANDLE)0xffffffff) {
      FUN_00401cc0("Could not open the file for reading");
    }
  }
  _Size = GetFileSize(local_c,(LPDWORD)0x0);
  lpBuffer = malloc(_Size);
  BVar1 = ReadFile(local_c,lpBuffer,_Size,param_2,(LPOVERLAPPED)0x0);
  if (BVar1 == 0) {
    FUN_00401cc0("Could not read the file");
  }
  return lpBuffer;
}



void __cdecl FUN_00402660(LPCSTR param_1,LPCVOID param_2,DWORD param_3)

{
  HANDLE local_c;
  DWORD local_8;
  
  if (param_1 == (LPCSTR)0x0) {
    local_c = GetStdHandle(0xfffffff5);
  }
  else {
    local_c = CreateFileA(param_1,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,1,0x80,(HANDLE)0x0);
  }
  if (local_c == (HANDLE)0xffffffff) {
    FUN_00401cc0("Could not open the file for writing (elfscrow won\'t overwrite files)");
  }
  WriteFile(local_c,param_2,param_3,&local_8,(LPOVERLAPPED)0x0);
  return;
}



void __cdecl FUN_004026d0(int param_1,LPCSTR param_2,LPCSTR param_3)

{
  void *_Memory;
  BOOL BVar1;
  FILE *pFVar2;
  char *_Format;
  char **_Format_00;
  BYTE *local_34;
  BYTE local_30;
  undefined local_2f;
  undefined2 local_2e;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  HCRYPTPROV local_10;
  HCRYPTKEY local_c;
  DWORD local_8;
  
  local_14 = DAT_00406008 ^ (uint)&stack0xfffffffc;
  _Memory = FUN_004025c0(param_2,&local_8);
  local_34 = (BYTE *)realloc(_Memory,local_8 + 0x10);
  BVar1 = CryptAcquireContextA
                    (&local_10,(LPCSTR)0x0,"Microsoft Enhanced Cryptographic Provider v1.0",1,
                     0xf0000000);
  if (BVar1 == 0) {
    FUN_00401cc0("CryptAcquireContext failed");
  }
  FUN_00401df0((int)&local_1c);
  FUN_00402540("Generated an encryption key",(int)&local_1c,8);
  local_30 = '\b';
  local_2f = 2;
  local_2e = 0;
  local_2c = 0x6601;
  local_28 = 8;
  local_24 = local_1c;
  local_20 = local_18;
  BVar1 = CryptImportKey(local_10,&local_30,0x14,0,1,&local_c);
  if (BVar1 == 0) {
    FUN_00401cc0("CryptImportKey failed for DES-CBC key");
  }
  BVar1 = CryptEncrypt(local_c,0,1,0,local_34,&local_8,local_8 + 8);
  if (BVar1 == 0) {
    FUN_00401cc0("CryptEncrypt failed");
                    // WARNING: Subroutine does not return
    exit(1);
  }
  FUN_00401f20(param_1,(int)&local_1c);
  _Format = "File successfully encrypted!\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format_00 = &_Format_00404834;
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,(char *)_Format_00);
  _Format = "    ++=====================++\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "    ||                     ||\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "    ||      ELF-SCROW      ||\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "    ||                     ||\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "    ||                     ||\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "    ||                     ||\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "    ||     O               ||\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "    ||     |               ||\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "    ||     |   (O)-        ||\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "    ||     |               ||\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "    ||     |               ||\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "    ||                     ||\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "    ||                     ||\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "    ||                     ||\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "    ||                     ||\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "    ||                     ||\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "    ++=====================++\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format_00 = &_Format_00404a58;
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,(char *)_Format_00);
  FUN_00402660(param_3,local_34,local_8);
  free(local_34);
  FUN_00403546();
  return;
}



void __cdecl FUN_00402a00(int param_1,LPCSTR param_2,LPCSTR param_3,char *param_4)

{
  BOOL BVar1;
  FILE *pFVar2;
  char *_Format;
  char **_Format_00;
  BYTE *local_34;
  BYTE local_30;
  undefined local_2f;
  undefined2 local_2e;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  HCRYPTPROV local_10;
  HCRYPTKEY local_c;
  DWORD local_8;
  
  local_14 = DAT_00406008 ^ (uint)&stack0xfffffffc;
  local_34 = (BYTE *)FUN_004025c0(param_2,&local_8);
  BVar1 = CryptAcquireContextA
                    (&local_10,(LPCSTR)0x0,"Microsoft Enhanced Cryptographic Provider v1.0",1,
                     0xf0000000);
  if (BVar1 == 0) {
    FUN_00401cc0("CryptAcquireContext failed");
  }
  FUN_00402220(param_1,(int)&local_1c,param_4);
  local_30 = '\b';
  local_2f = 2;
  local_2e = 0;
  local_2c = 0x6601;
  local_28 = 8;
  local_24 = local_1c;
  local_20 = local_18;
  BVar1 = CryptImportKey(local_10,&local_30,0x14,0,1,&local_c);
  if (BVar1 == 0) {
    FUN_00401cc0("CryptImportKey failed for DES-CBC key");
  }
  BVar1 = CryptDecrypt(local_c,0,1,0,local_34,&local_8);
  if (BVar1 == 0) {
    FUN_00401cc0("CryptDecrypt failed");
                    // WARNING: Subroutine does not return
    exit(1);
  }
  _Format = "File successfully decrypted!\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format_00 = &_Format_00404b04;
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,(char *)_Format_00);
  _Format = "  +----------------------+\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "  |\\                    /\\\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "  | \\ ________________ / |\\\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "  |  |                |  | \\\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "  |  | +------------+ |  |  \\\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "  |  | |\\          /| |  |   \\\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "  |  | | \\        / | |  |    \\\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "  |  | |  \\      /  | |  |     \\\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "  |  | |   \\    /   | |  |     |\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "  |  | |    \\  /    | |  |     |\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "  |  | |     \\/     | |  |     |\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "  |  | |            | |  |     |\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "  |  | |            | |  |     |\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "  |  |_|   SECRET   |_|  |     |\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "  | /  +------------+  \\ |     |\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "  |/                    \\|     |\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "  +----------------------\\     |\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "                          \\    |\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "                           \\   |\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "                            \\  |\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "                             \\ |\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "                              \\|\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format = "                               |\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format_00 = &_Format_00404e24;
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,(char *)_Format_00);
  FUN_00402660(param_3,local_34,local_8);
  FUN_00403546();
  return;
}



void FUN_00402d80(undefined4 param_1)

{
  FILE *pFVar1;
  char *_Format;
  undefined4 uVar2;
  
  _Format = 
  "Are you encrypting a file? Try --encrypt! For example:\n\n  %s --encrypt <infile> <outfile>\n\nYou\'ll be given a secret ID. Keep it safe! The only way to get the file\nback is to use that secret ID to decrypt it, like this:\n\n  %s --decrypt --id=<secret_id> <infile> <outfile>\n\nYou can optionally pass --insecure to use unencrypted HTTP. But if you\ndo that, you\'ll be vulnerable to packet sniffers such as Wireshark that\ncould potentially snoop on your traffic to figure out what\'s going on!\n"
  ;
  uVar2 = param_1;
  pFVar1 = __iob_func();
  fprintf(pFVar1 + 2,_Format,param_1,uVar2);
                    // WARNING: Subroutine does not return
  exit(0);
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 __cdecl FUN_00402db0(int param_1,undefined4 *param_2)

{
  byte bVar1;
  FILE *pFVar2;
  int iVar3;
  bool bVar4;
  char *_Format;
  char **_Format_00;
  int local_134;
  byte *local_12c;
  char *local_128;
  int local_120;
  byte *local_118;
  byte *local_114;
  int local_10c;
  byte *local_104;
  char *local_100;
  int local_f8;
  byte *local_f0;
  char *local_ec;
  int local_e4;
  byte *local_dc;
  char *local_d8;
  int local_d0;
  byte *local_c8;
  byte *local_c4;
  int local_bc;
  byte *local_b4;
  byte *local_b0;
  byte *local_a4 [4];
  undefined *local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  char *local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  char *local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  char *local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined *local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  char *local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  LPCSTR local_20;
  LPCSTR local_1c;
  byte *local_18;
  int local_14;
  int local_10;
  int local_c;
  char *local_8;
  
  local_a4[0] = &DAT_00405010;
  local_a4[1] = 0;
  local_a4[2] = 0;
  local_a4[3] = 0;
  local_94 = &DAT_00405018;
  local_90 = 0;
  local_8c = 0;
  local_88 = 0;
  local_84 = "version";
  local_80 = 0;
  local_7c = 0;
  local_78 = 0;
  local_74 = "encrypt";
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  local_64 = "decrypt";
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = &DAT_00405034;
  local_50 = 1;
  local_4c = 0;
  local_48 = 0;
  local_44 = "insecure";
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_14 = 0;
  local_c = 0;
  local_8 = (char *)0x0;
  local_20 = (LPCSTR)0x0;
  local_1c = (LPCSTR)0x0;
  local_10 = 0;
  _Format = "Welcome to ElfScrow V1.01, the only encryption trusted by Santa!\n";
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,_Format);
  _Format_00 = &_Format_0040508c;
  pFVar2 = __iob_func();
  fprintf(pFVar2 + 2,(char *)_Format_00);
  _DAT_00406004 = 0;
  do {
    while( true ) {
      iVar3 = FUN_00401c90(param_1,param_2,"",(int)local_a4,&local_24);
      if (iVar3 == -1) {
        if (DAT_00406000 < param_1) {
          local_20 = (LPCSTR)param_2[DAT_00406000];
          DAT_00406000 = DAT_00406000 + 1;
        }
        else {
          _Format = 
          "\n* WARNING: You\'re reading from stdin. That only partially works, use at your own risk!\n\n"
          ;
          pFVar2 = __iob_func();
          fprintf(pFVar2 + 2,_Format);
        }
        if (DAT_00406000 < param_1) {
          local_1c = (LPCSTR)param_2[DAT_00406000];
          DAT_00406000 = DAT_00406000 + 1;
        }
        if (local_c == local_14) {
          _Format = "** Please pick --encrypt or --decrypt!\n\n";
          pFVar2 = __iob_func();
          fprintf(pFVar2 + 2,_Format);
          FUN_00402d80(*param_2);
        }
        if ((local_c != 0) && (local_8 == (char *)0x0)) {
          _Format = "** You need an --id to --decrypt!\n\n";
          pFVar2 = __iob_func();
          fprintf(pFVar2 + 2,_Format);
          FUN_00402d80(*param_2);
        }
        if (local_10 != 0) {
          _Format = 
          "*** WARNING: This traffic is using insecure HTTP and can be logged with tools such as Wireshark\n\n"
          ;
          pFVar2 = __iob_func();
          fprintf(pFVar2 + 2,_Format);
        }
        if (local_14 == 0) {
          FUN_00402a00(local_10,local_20,local_1c,local_8);
        }
        else {
          FUN_004026d0(local_10,local_20,local_1c);
        }
        return 0;
      }
      if (iVar3 == 0) break;
      _Format = "Unknown option\n\n";
      pFVar2 = __iob_func();
      fprintf(pFVar2 + 2,_Format);
      FUN_00402d80(*param_2);
    }
    local_18 = local_a4[local_24 * 4];
    local_b0 = &DAT_00405090;
    local_b4 = local_18;
    do {
      bVar1 = *local_b4;
      bVar4 = bVar1 < *local_b0;
      if (bVar1 != *local_b0) {
LAB_00402fe3:
        local_bc = (1 - (uint)bVar4) - (uint)(bVar4 != false);
        goto LAB_00402fee;
      }
      if (bVar1 == 0) break;
      bVar1 = local_b4[1];
      bVar4 = bVar1 < local_b0[1];
      if (bVar1 != local_b0[1]) goto LAB_00402fe3;
      local_b4 = local_b4 + 2;
      local_b0 = local_b0 + 2;
    } while (bVar1 != 0);
    local_bc = 0;
LAB_00402fee:
    if (local_bc == 0) {
LAB_00403098:
      FUN_00402d80(*param_2);
    }
    else {
      local_c4 = &DAT_00405098;
      local_c8 = local_18;
      do {
        bVar1 = *local_c8;
        bVar4 = bVar1 < *local_c4;
        if (bVar1 != *local_c4) {
LAB_00403078:
          local_d0 = (1 - (uint)bVar4) - (uint)(bVar4 != false);
          goto LAB_00403083;
        }
        if (bVar1 == 0) break;
        bVar1 = local_c8[1];
        bVar4 = bVar1 < local_c4[1];
        if (bVar1 != local_c4[1]) goto LAB_00403078;
        local_c8 = local_c8 + 2;
        local_c4 = local_c4 + 2;
      } while (bVar1 != 0);
      local_d0 = 0;
LAB_00403083:
      if (local_d0 == 0) goto LAB_00403098;
    }
    local_d8 = "version";
    local_dc = local_18;
    do {
      bVar1 = *local_dc;
      bVar4 = bVar1 < (byte)*local_d8;
      if (bVar1 != *local_d8) {
LAB_00403117:
        local_e4 = (1 - (uint)bVar4) - (uint)(bVar4 != false);
        goto LAB_00403122;
      }
      if (bVar1 == 0) break;
      bVar1 = local_dc[1];
      bVar4 = bVar1 < ((byte *)local_d8)[1];
      if (bVar1 != ((byte *)local_d8)[1]) goto LAB_00403117;
      local_dc = local_dc + 2;
      local_d8 = (char *)((byte *)local_d8 + 2);
    } while (bVar1 != 0);
    local_e4 = 0;
LAB_00403122:
    if (local_e4 == 0) {
      _Format = "ElfScrow V1.01 (client)\n";
      pFVar2 = __iob_func();
      fprintf(pFVar2 + 2,_Format);
                    // WARNING: Subroutine does not return
      exit(0);
    }
    local_ec = "encrypt";
    local_f0 = local_18;
    do {
      bVar1 = *local_f0;
      bVar4 = bVar1 < (byte)*local_ec;
      if (bVar1 != *local_ec) {
LAB_004031cd:
        local_f8 = (1 - (uint)bVar4) - (uint)(bVar4 != false);
        goto LAB_004031d8;
      }
      if (bVar1 == 0) break;
      bVar1 = local_f0[1];
      bVar4 = bVar1 < ((byte *)local_ec)[1];
      if (bVar1 != ((byte *)local_ec)[1]) goto LAB_004031cd;
      local_f0 = local_f0 + 2;
      local_ec = (char *)((byte *)local_ec + 2);
    } while (bVar1 != 0);
    local_f8 = 0;
LAB_004031d8:
    if (local_f8 == 0) {
      local_14 = 1;
    }
    else {
      local_100 = "decrypt";
      local_104 = local_18;
      do {
        bVar1 = *local_104;
        bVar4 = bVar1 < (byte)*local_100;
        if (bVar1 != *local_100) {
LAB_0040326a:
          local_10c = (1 - (uint)bVar4) - (uint)(bVar4 != false);
          goto LAB_00403275;
        }
        if (bVar1 == 0) break;
        bVar1 = local_104[1];
        bVar4 = bVar1 < ((byte *)local_100)[1];
        if (bVar1 != ((byte *)local_100)[1]) goto LAB_0040326a;
        local_104 = local_104 + 2;
        local_100 = (char *)((byte *)local_100 + 2);
      } while (bVar1 != 0);
      local_10c = 0;
LAB_00403275:
      if (local_10c == 0) {
        local_c = 1;
      }
      else {
        local_114 = &DAT_004050d0;
        local_118 = local_18;
        do {
          bVar1 = *local_118;
          bVar4 = bVar1 < *local_114;
          if (bVar1 != *local_114) {
LAB_00403307:
            local_120 = (1 - (uint)bVar4) - (uint)(bVar4 != false);
            goto LAB_00403312;
          }
          if (bVar1 == 0) break;
          bVar1 = local_118[1];
          bVar4 = bVar1 < local_114[1];
          if (bVar1 != local_114[1]) goto LAB_00403307;
          local_118 = local_118 + 2;
          local_114 = local_114 + 2;
        } while (bVar1 != 0);
        local_120 = 0;
LAB_00403312:
        if (local_120 == 0) {
          local_8 = DAT_00406024;
        }
        else {
          local_128 = "insecure";
          local_12c = local_18;
          do {
            bVar1 = *local_12c;
            bVar4 = bVar1 < (byte)*local_128;
            if (bVar1 != *local_128) {
LAB_004033a5:
              local_134 = (1 - (uint)bVar4) - (uint)(bVar4 != false);
              goto LAB_004033b0;
            }
            if (bVar1 == 0) break;
            bVar1 = local_12c[1];
            bVar4 = bVar1 < ((byte *)local_128)[1];
            if (bVar1 != ((byte *)local_128)[1]) goto LAB_004033a5;
            local_12c = local_12c + 2;
            local_128 = (char *)((byte *)local_128 + 2);
          } while (bVar1 != 0);
          local_134 = 0;
LAB_004033b0:
          if (local_134 == 0) {
            local_10 = 1;
          }
          else {
            _Format = "Unknown option\n\n";
            pFVar2 = __iob_func();
            fprintf(pFVar2 + 2,_Format);
            FUN_00402d80(*param_2);
          }
        }
      }
    }
  } while( true );
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void __fastcall FUN_00403546(int param_1,undefined4 param_2)

{
  undefined4 in_EAX;
  HANDLE hProcess;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined2 in_ES;
  undefined2 in_CS;
  undefined2 in_SS;
  undefined2 in_DS;
  undefined2 in_FS;
  undefined2 in_GS;
  byte in_PF;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  undefined4 local_res0;
  UINT uExitCode;
  int local_32c;
  undefined4 local_328;
  
  if (param_1 == DAT_00406008) {
    return;
  }
  _DAT_00406168 =
       (uint)(in_NT & 1) * 0x4000 | (uint)SBORROW4((int)&stack0xfffffffc,0x328) * 0x800 |
       (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 | (uint)((int)&local_32c < 0) * 0x80 |
       (uint)((undefined *)register0x00000010 == (undefined *)0x32c) * 0x40 |
       (uint)(in_AF & 1) * 0x10 | (uint)(in_PF & 1) * 4 |
       (uint)(&stack0xfffffffc < (undefined *)0x328) | (uint)(in_ID & 1) * 0x200000 |
       (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000;
  _DAT_0040616c = &stack0x00000004;
  _DAT_004060a8 = 0x10001;
  _DAT_00406050 = 0xc0000409;
  _DAT_00406054 = 1;
  local_32c = DAT_00406008;
  local_328 = DAT_0040600c;
  _DAT_0040605c = local_res0;
  _DAT_00406134 = in_GS;
  _DAT_00406138 = in_FS;
  _DAT_0040613c = in_ES;
  _DAT_00406140 = in_DS;
  _DAT_00406144 = unaff_EDI;
  _DAT_00406148 = unaff_ESI;
  _DAT_0040614c = unaff_EBX;
  _DAT_00406150 = param_2;
  _DAT_00406154 = param_1;
  _DAT_00406158 = in_EAX;
  _DAT_0040615c = unaff_EBP;
  DAT_00406160 = local_res0;
  _DAT_00406164 = in_CS;
  _DAT_00406170 = in_SS;
  _DAT_004060a0 = IsDebuggerPresent();
  _crt_debugger_hook(1);
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  UnhandledExceptionFilter((_EXCEPTION_POINTERS *)&ExceptionInfo_0040521c);
  if (_DAT_004060a0 == 0) {
    _crt_debugger_hook(1);
  }
  uExitCode = 0xc0000409;
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



// WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4
// WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3
// WARNING: Globals starting with '_' overlap smaller symbols at the same address

int entry(void)

{
  bool bVar1;
  LONG LVar2;
  int Exchange;
  BOOL BVar3;
  int in_FS_OFFSET;
  
  ___security_init_cookie();
  Exchange = *(int *)(*(int *)(in_FS_OFFSET + 0x18) + 4);
  bVar1 = false;
  do {
    LVar2 = InterlockedCompareExchange((LONG *)&DAT_0040638c,Exchange,0);
    if (LVar2 == 0) {
LAB_004035eb:
      if (DAT_00406388 == 1) {
        _amsg_exit(0x1f);
      }
      else {
        if (DAT_00406388 == 0) {
          DAT_00406388 = 1;
          Exchange = _initterm_e(&DAT_0040412c,&DAT_00404138);
          if (Exchange != 0) {
            return 0xff;
          }
        }
        else {
          _DAT_0040604c = 1;
        }
      }
      if (DAT_00406388 == 1) {
        _initterm(&DAT_00404120,&DAT_00404128);
        DAT_00406388 = 2;
      }
      if (!bVar1) {
        InterlockedExchange((LONG *)&DAT_0040638c,0);
      }
      if ((_DAT_00406398 != (code *)0x0) &&
         (BVar3 = __IsNonwritableInCurrentImage(&DAT_00406398), BVar3 != 0)) {
        (*_DAT_00406398)(0,2,0);
      }
      *(undefined4 *)__initenv_exref = DAT_00406034;
      DAT_00406048 = FUN_00402db0(DAT_00406030,DAT_00406038);
      if (_DAT_0040603c != 0) {
        if (_DAT_0040604c == 0) {
          _cexit();
        }
        return DAT_00406048;
      }
                    // WARNING: Subroutine does not return
      exit(DAT_00406048);
    }
    if (LVar2 == Exchange) {
      bVar1 = true;
      goto LAB_004035eb;
    }
    Sleep(1000);
  } while( true );
}



// Library Function - Single Match
// Name: ?__CxxUnhandledExceptionFilter@@YGJPAU_EXCEPTION_POINTERS@@@Z
// Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release
// long __stdcall __CxxUnhandledExceptionFilter(struct _EXCEPTION_POINTERS *)

long __CxxUnhandledExceptionFilter(_EXCEPTION_POINTERS *param_1)

{
  PEXCEPTION_RECORD pEVar1;
  ULONG_PTR UVar2;
  
  pEVar1 = param_1->ExceptionRecord;
  if (((pEVar1->ExceptionCode == 0xe06d7363) && (pEVar1->NumberParameters == 3)) &&
     ((UVar2 = pEVar1->ExceptionInformation[0], UVar2 == 0x19930520 ||
      (((UVar2 == 0x19930521 || (UVar2 == 0x19930522)) || (UVar2 == 0x1994000)))))) {
    terminate();
  }
  return 0;
}



// WARNING: Exceeded maximum restarts with more pending

void __cdecl _amsg_exit(int param_1)

{
                    // WARNING: Could not recover jumptable at 0x00403958. Too many branches
                    // WARNING: Treating indirect jump as call
  _amsg_exit();
  return;
}



// WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4
// WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3
// Library Function - Single Match
// Name: __onexit
// Library: Visual Studio 2008 Release

_onexit_t __cdecl __onexit(_onexit_t param_1)

{
  _onexit_t p_Var1;
  undefined4 uVar2;
  undefined4 local_24;
  int local_20 [5];
  undefined4 uStack12;
  undefined *local_8;
  
  local_8 = &DAT_00405308;
  uStack12 = 0x40396a;
  local_20[0] = _decode_pointer(DAT_00406394);
  if (local_20[0] == -1) {
    p_Var1 = _onexit(param_1);
  }
  else {
    _lock(8);
    local_8 = (undefined *)0x0;
    local_20[0] = _decode_pointer(DAT_00406394);
    local_24 = _decode_pointer(DAT_00406390);
    uVar2 = _encode_pointer(param_1,local_20,&local_24);
    p_Var1 = (_onexit_t)__dllonexit(uVar2);
    DAT_00406394 = _encode_pointer(local_20[0]);
    DAT_00406390 = _encode_pointer(local_24);
    local_8 = (undefined *)0xfffffffe;
    FUN_004039fa();
  }
  return p_Var1;
}



void FUN_004039fa(void)

{
  _unlock(8);
  return;
}



// Library Function - Single Match
// Name: _atexit
// Library: Visual Studio 2008 Release

int __cdecl _atexit(void *param_1)

{
  _onexit_t p_Var1;
  
  p_Var1 = __onexit((_onexit_t)param_1);
  return (uint)(p_Var1 != (_onexit_t)0x0) - 1;
}



// WARNING: Removing unreachable block (ram,0x00403a2e)
// WARNING: Removing unreachable block (ram,0x00403a34)
// WARNING: Removing unreachable block (ram,0x00403a36)

void FUN_00403a1a(void)

{
  return;
}



// WARNING: Exceeded maximum restarts with more pending

int __cdecl _XcptFilter(ulong _ExceptionNum,_EXCEPTION_POINTERS *_ExceptionPtr)

{
  int iVar1;
  
                    // WARNING: Could not recover jumptable at 0x00403a66. Too many branches
                    // WARNING: Treating indirect jump as call
  iVar1 = _XcptFilter();
  return iVar1;
}



// Library Function - Single Match
// Name: __ValidateImageBase
// Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release

BOOL __cdecl __ValidateImageBase(PBYTE pImageBase)

{
  if ((*(short *)pImageBase == 0x5a4d) &&
     (*(int *)(pImageBase + *(int *)(pImageBase + 0x3c)) == 0x4550)) {
    return (uint)(*(short *)(pImageBase + *(int *)(pImageBase + 0x3c) + 6) == 0x10b);
  }
  return 0;
}



// Library Function - Single Match
// Name: __FindPESection
// Library: Visual Studio 2008 Release

PIMAGE_SECTION_HEADER __cdecl __FindPESection(PBYTE pImageBase,DWORD_PTR rva)

{
  PIMAGE_SECTION_HEADER p_Var1;
  uint uVar2;
  
  pImageBase = pImageBase + *(int *)(pImageBase + 0x3c);
  uVar2 = 0;
  p_Var1 = (PIMAGE_SECTION_HEADER)(pImageBase + (uint)*(ushort *)(pImageBase + 0x14) + 0x18);
  if (*(ushort *)(pImageBase + 6) != 0) {
    do {
      if ((p_Var1->VirtualAddress <= rva) && (rva < p_Var1->Misc + p_Var1->VirtualAddress)) {
        return p_Var1;
      }
      uVar2 = uVar2 + 1;
      p_Var1 = p_Var1 + 1;
    } while (uVar2 < *(ushort *)(pImageBase + 6));
  }
  return (PIMAGE_SECTION_HEADER)0x0;
}



// Library Function - Single Match
// Name: __IsNonwritableInCurrentImage
// Library: Visual Studio 2008 Release

BOOL __cdecl __IsNonwritableInCurrentImage(PBYTE pTarget)

{
  uint uVar1;
  BOOL BVar2;
  PIMAGE_SECTION_HEADER p_Var3;
  int **in_FS_OFFSET;
  uint uStack44;
  uint *local_1c;
  int *local_14;
  code *pcStack16;
  uint local_c;
  undefined4 local_8;
  
  pcStack16 = FUN_00403c25;
  local_14 = *in_FS_OFFSET;
  local_c = DAT_00406008 ^ 0x405328;
  uStack44 = DAT_00406008 ^ (uint)&stack0xfffffffc;
  local_1c = &uStack44;
  *(int ***)in_FS_OFFSET = &local_14;
  local_8 = 0;
  BVar2 = __ValidateImageBase((PBYTE)&IMAGE_DOS_HEADER_00400000);
  if (BVar2 != 0) {
    p_Var3 = __FindPESection((PBYTE)&IMAGE_DOS_HEADER_00400000,(DWORD_PTR)(pTarget + -0x400000));
    if (p_Var3 != (PIMAGE_SECTION_HEADER)0x0) {
      uVar1 = p_Var3->Characteristics;
      *in_FS_OFFSET = local_14;
      return ~(uVar1 >> 0x1f) & 1;
    }
  }
  *in_FS_OFFSET = local_14;
  return 0;
}



void _initterm(void)

{
                    // WARNING: Could not recover jumptable at 0x00403bbe. Too many branches
                    // WARNING: Treating indirect jump as call
  _initterm();
  return;
}



void _initterm_e(void)

{
                    // WARNING: Could not recover jumptable at 0x00403bc4. Too many branches
                    // WARNING: Treating indirect jump as call
  _initterm_e();
  return;
}



// WARNING: This is an inlined function
// WARNING: Unable to track spacebase fully for stack
// WARNING: Variable defined which should be unmapped: param_2
// Library Function - Single Match
// Name: __SEH_prolog4
// Libraries: Visual Studio 2005, Visual Studio 2008, Visual Studio 2010, Visual Studio 2012

void __cdecl __SEH_prolog4(undefined4 param_1,int param_2)

{
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  int *in_FS_OFFSET;
  undefined4 local_res0;
  uint auStack28 [5];
  undefined local_8 [8];
  
  param_2 = -param_2;
  *(undefined4 *)((int)auStack28 + param_2 + 0x10) = unaff_EBX;
  *(undefined4 *)((int)auStack28 + param_2 + 0xc) = unaff_ESI;
  *(undefined4 *)((int)auStack28 + param_2 + 8) = unaff_EDI;
  *(uint *)((int)auStack28 + param_2 + 4) = DAT_00406008 ^ (uint)&param_2;
  *(uint *)((int)auStack28 + param_2) = local_res0;
  *(undefined **)in_FS_OFFSET = local_8;
  return;
}



// WARNING: This is an inlined function
// Library Function - Single Match
// Name: __SEH_epilog4
// Libraries: Visual Studio 2005, Visual Studio 2008, Visual Studio 2010, Visual Studio 2012

void __SEH_epilog4(void)

{
  undefined4 *unaff_EBP;
  undefined4 *in_FS_OFFSET;
  undefined4 unaff_retaddr;
  
  *in_FS_OFFSET = unaff_EBP[-4];
  *unaff_EBP = unaff_retaddr;
  return;
}



void __cdecl
FUN_00403c25(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  _except_handler4_common(&DAT_00406008,FUN_00403546,param_1,param_2,param_3,param_4);
  return;
}



void FUN_00403c4a(void)

{
  errno_t eVar1;
  
  eVar1 = _controlfp_s((uint *)0x0,0x10000,0x30000);
  if (eVar1 != 0) {
    _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
  }
  return;
}



undefined4 FUN_00403c75(void)

{
  return 0;
}



// Library Function - Single Match
// Name: ___security_init_cookie
// Library: Visual Studio 2008 Release

void __cdecl ___security_init_cookie(void)

{
  DWORD DVar1;
  DWORD DVar2;
  DWORD DVar3;
  uint uVar4;
  uint local_14;
  uint local_10;
  _FILETIME local_c;
  
  local_c.dwLowDateTime = 0;
  local_c.dwHighDateTime = 0;
  if ((DAT_00406008 == 0xbb40e64e) || ((DAT_00406008 & 0xffff0000) == 0)) {
    GetSystemTimeAsFileTime((LPFILETIME)&local_c);
    uVar4 = local_c.dwHighDateTime ^ local_c.dwLowDateTime;
    DVar1 = GetCurrentProcessId();
    DVar2 = GetCurrentThreadId();
    DVar3 = GetTickCount();
    QueryPerformanceCounter((LARGE_INTEGER *)&local_14);
    DAT_00406008 = uVar4 ^ DVar1 ^ DVar2 ^ DVar3 ^ local_10 ^ local_14;
    if (DAT_00406008 == 0xbb40e64e) {
      DAT_00406008 = 0xbb40e64f;
    }
    else {
      if ((DAT_00406008 & 0xffff0000) == 0) {
        DAT_00406008 = DAT_00406008 | DAT_00406008 << 0x10;
      }
    }
    DAT_0040600c = ~DAT_00406008;
  }
  else {
    DAT_0040600c = ~DAT_00406008;
  }
  return;
}



// WARNING: Exceeded maximum restarts with more pending

void __cdecl _crt_debugger_hook(int param_1)

{
                    // WARNING: Could not recover jumptable at 0x00403d0e. Too many branches
                    // WARNING: Treating indirect jump as call
  _crt_debugger_hook();
  return;
}



// WARNING: Exceeded maximum restarts with more pending

void __cdecl terminate(void)

{
                    // WARNING: Could not recover jumptable at 0x00403d14. Too many branches
                    // WARNING: Treating indirect jump as call
  terminate();
  return;
}



// WARNING: Exceeded maximum restarts with more pending

void __cdecl _unlock(int _File)

{
                    // WARNING: Could not recover jumptable at 0x00403d1a. Too many branches
                    // WARNING: Treating indirect jump as call
  _unlock();
  return;
}



void __dllonexit(void)

{
                    // WARNING: Could not recover jumptable at 0x00403d20. Too many branches
                    // WARNING: Treating indirect jump as call
  __dllonexit();
  return;
}



// WARNING: Exceeded maximum restarts with more pending

void __cdecl _lock(int _File)

{
                    // WARNING: Could not recover jumptable at 0x00403d26. Too many branches
                    // WARNING: Treating indirect jump as call
  _lock();
  return;
}



void _except_handler4_common(void)

{
                    // WARNING: Could not recover jumptable at 0x00403d2c. Too many branches
                    // WARNING: Treating indirect jump as call
  _except_handler4_common();
  return;
}



// WARNING: Exceeded maximum restarts with more pending

void __cdecl
_invoke_watson(wchar_t *param_1,wchar_t *param_2,wchar_t *param_3,uint param_4,uintptr_t param_5)

{
                    // WARNING: Could not recover jumptable at 0x00403d32. Too many branches
                    // WARNING: Treating indirect jump as call
  _invoke_watson();
  return;
}



// WARNING: Exceeded maximum restarts with more pending

errno_t __cdecl _controlfp_s(uint *_CurrentState,uint _NewValue,uint _Mask)

{
  errno_t eVar1;
  
                    // WARNING: Could not recover jumptable at 0x00403d38. Too many branches
                    // WARNING: Treating indirect jump as call
  eVar1 = _controlfp_s();
  return eVar1;
}


