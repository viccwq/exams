# -*- coding: utf-8 -*-
"""
Created on Tue May 09 14:57:55 2017

@author: VIC
"""
import random
import sys, os
import binascii

def ascii2hex(file_read):
    print "file \"%s\" is to be converted!"%(file_read)
    #read the ASCII file
    fa = open(file_read, "r")    
    lines = fa.readlines()
    count = len(lines)
    fa.close()
    
    #print lines
    print "count is: %d" %(count)
    #convert ascii to hex
    data = bytearray(count)
    for i in range(0, count):
        data[i] = int(lines[i], 16)
        #print (lines[i], data[i])
        
    #save file
    file_save = "%s.hex" % (file_read)
    print "file \"%s\" is to be save!"%(file_save)
    fh = open(file_save, "wb")
    fh.write(data)
    fh.close()

def hex2ascii(file_read, file_save):
    print "source file is:\"%s\""%(file_read)
    print "save file is:\"%s\""%(file_save)
    
    #get the counter of the fsn
    fs = open(file_read, "rb")
    fs.seek(20, os.SEEK_SET)
    hexstr = ""
    for i in range(4):    
        a = fs.read(1)
        hexstr = binascii.b2a_hex(a) + hexstr
    fs.close()
    
    counter = int(hexstr, 16)
    print "there are %d items"%(counter)
    print "Please set the start index:"
    str_file = raw_input("input:")
    
    fs = open(file_read, "rb")
    #skip the head
    fs.seek(32, os.SEEK_SET)
    #go to the fsn
    fs.seek(26, os.SEEK_CUR)
    str_file = ""
    for i in range(counter):
        s1 = ""
        for j in range(10):
            s1 = s1 + fs.read(1)
            fs.read(1)
        print "%s"%(s1)
        str_file += s1 + "\n"
        fs.seek((1644 - 20), os.SEEK_CUR)
    fs.close()
    
    fh = open(file_save, "a")
    fh.write(str_file)
    fh.close()
    print "file \"%s\" is saved"%(file_save)

if __name__ == "__main__":
    hex2ascii(sys.argv[1], sys.argv[2])

