#!/usr/bin/python   
#-*-coding:utf-8-*-  
import cv2.cv as cv
import random
import sys, os

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

def hex2ascii(file_name):
    print "file \"%s\" is to be converted!"%(file_name)
    print "aaa"

if __name__ == "__main__":
    ascii2hex(sys.argv[1])
