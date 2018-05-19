#Welcome to this OSX Csu-85 wiki!

##Building the missing Mac "crt0.o" File

Have you noticed simple to apply GNU configure flags to statically link executables fail for more sophisticated software package distributions? Have you compiled code that complains about crt0.o not being found? You are not alone. You have to go out of your way to forcibly static link compound packages in a Mac environment.

Other than posting the source code, Apple has made it extremely difficult to compile statically linked executables for portability reasons. An understandable endeaver... However, at times at the cost of trading off portability, security and possible optimization reasons may require building truly monolithic statically-linked executables. Additionally building a cross compiler toolchain on a Mac may require the infamous crt0.o used to load programs into the OS for execution without dynamically linking any libraries or frameworks. Having a functioning "C RunTime 0" object file appears to be a critical step for bootstrapping a cross compiler using libc. (crt1.o is used to load dynamic linked programs.)

Through pure happenstance after trying to build a GNU cross compiler on a Mac a year ago, I ran across Apple's complete listing complete listing of different "C start up" (Csu) packages and the [qa1118](https://developer.apple.com/library/mac/qa/qa1118/_index.html) jewel. Additionally, upon examination of [Apple's Open Source Homepage](http://www.opensource.apple.com/) it is possible to deduce which OS versions uses which Csu-XX package. In a nutshell, OSX 10.6 - 10.9 use Csu-79. Yosemite (10.0) uses Csu-85.

When you unbundle say a Csu-85 package using "tar xvzf Csu-85.tar.gz" from Apple or a clone of this project, you will notice a complete lack of documentation. However, the the all important UNIX assembly source code file called start.s exists. Inside the file is an include reference to Availability.h.

With a little educated guesswork and applying the UNIX find command, I deduced two missing headers for my 10.10 environment where located within the 10.10 SDK, /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.10.sdk/usr/include. Different OSX SDKs are likely to have slightly different **Availability.h** and **AvailabilityInternal.h**. The complete list assembly and C files in Csu-85 are provided below.

     Assembly Code:

       1. start.s
       2. dyld_glue.s
       3. lazy_dylib_helper.s

     C Code:

       1. crt.c
       2. icplusplus.c
       3. lazy_dylib_loader.c

To get the code to compile, the Mac assembler (as) needs to know where the header files are to be found using the -I flag. To romance the Makefile to get the assembler produce desired linking objects, try executing **make ARCH_CFLAGS=-I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.10.sdk/usr/include** within the Csu-85 directory. The following new files will appear.

    Object Code Files:

      bundle1.v1.o
      crt0.o
      crt1.v1.o
      crt1.v2.o
      crt1.v3.o
      crt1.v4.o
      dylib1.v1.o
      dylib1.v2.o
      gcrt1.o
      lazydylib1.o

Running out of time for detailing how to perform the associated **make install**, which will rename a few files above creating the following object files:

    bundle1.o
    crt0.o
    crt1.10.5.o
    crt1.10.6.o
    crt1.o
    dylib1.10.5.o
    dylib1.o
    gcrt1.o
    lazydylib1.o

Hope this information will excite a few hard-core developers.

BEWARE - I have not applied the information above to determine that it works properly. More information to come.

Cheers,
Skaht
