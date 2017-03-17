# -*- coding: utf-8 -*-
"""
Created on Fri Mar 17 13:56:44 2017

@author: VIC
"""
import os
import shutil
import sys
import numpy as np
if __name__ == '__main__':
    #print ("%d"%len(sys.argv))
    #get current dir
    cur_dir=os.getcwd()
    input_dir=""
    output_dir=""
    
    if len(sys.argv) < 2:
        print ("Please intput input or output folder!")
        exit()
    elif len(sys.argv) < 3:
        input_dir = cur_dir
        output_dir = sys.argv[1]
    else:
        input_dir = sys.argv[1]
        output_dir = sys.argv[2]
        
    if input_dir == output_dir:
        print ("the input should not the same as output folder!")
        exit()
        
    print "intput folder: "+input_dir
    print "output folder: "+output_dir
    
    #exit if the source is not exist
    if not os.path.isdir(input_dir):
        print "\""+input_dir+"\" is not exist"
        exit()
        
    #create directory if the destination is not exist
    #otherwise it clean the folder    
    if not os.path.isdir(output_dir):
        print "\""+output_dir+"\" is not exist"
        os.makedirs(output_dir)
        print "\""+output_dir+"\" is created"           
        
    index=0
    for file in os.listdir(input_dir):
        if os.path.isfile(os.path.join(input_dir,file)):
            if file.find('.bmp') > 0:
                index+=1
                rename_file = ("%06d.bmp"%index)
                print file+" ==> "+rename_file
                shutil.copy(os.path.join(input_dir,file), \
                            os.path.join(output_dir, rename_file))

            
        


