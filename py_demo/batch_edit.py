# -*- coding: utf-8 -*-
"""
Created on Fri Mar 17 13:56:44 2017

@author: VIC
"""
import cv2
import os
import shutil
import sys
import numpy as np

#remove the white pixel in the left side of the image
def pixel_eidt(src_file, dst_file):
    #print "souce image is %s"%(src_file)
    #print "destination image is %s"%(dst_file)
    #img
    src_img = cv2.imread(src_file, 0)
    #print (src_img.shape)
    #print (type(src_img))
    
    (height, width) = src_img.shape
    for i in range(0, height):
        for j in range(0, 12):
            #print (src_img[i, j ,:])
            src_img[i, j] = (0)
            
    cv2.imwrite(dst_file, cv2.flip(src_img, 0))        
    #cv2.imshow(src_file, src_img)
    #cv2.waitKey(0)
    #cv2.destroyWindow(src_file)
    return

def pixel_eidt_2(src_file, dst_file):
    #print "souce image is %s"%(src_file)
    #print "destination image is %s"%(dst_file)
    #img
    src_img = cv2.imread(src_file, 0)
    #print (src_img.shape)
    #print (type(src_img))
    
    (height, width) = src_img.shape
    for i in range(0, height):
        for j in range(width-31, width):
            #print (src_img[i, j ,:])
            src_img[i, j] = (0)
            
    cv2.imwrite(dst_file, cv2.flip(src_img, 0))        
    #cv2.imshow(src_file, src_img)
    #cv2.waitKey(0)
    #cv2.destroyWindow(src_file)
    return

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
    
    print "Please choose the action:"
    print "1. deleted the white strip in the left"
    print "2. deleted the white strip in the right"
    str = raw_input("input:")
    mode = int(str)
    print "choosed %d"%mode
    print "Please set the start index:"
    str = raw_input("input:")
    index = int(str)
    print "start index is %d"%index
    str = raw_input("Press any key to continue")
    for file in os.listdir(input_dir):
        if os.path.isfile(os.path.join(input_dir,file)):
            if file.find('.bmp') > 0:
                rename_file = ("%06d.bmp"%index)
                print file+" ==> "+rename_file
                #shutil.copy(os.path.join(input_dir,file), \
                #            os.path.join(output_dir, rename_file))
                if 1 == mode:
                    pixel_eidt(os.path.join(input_dir,file), \
                            os.path.join(output_dir, rename_file))
                elif 2 == mode:
                    pixel_eidt_2(os.path.join(input_dir,file), \
                            os.path.join(output_dir, rename_file))
                else:
                    exit()
                index+=1
                        

            
        


