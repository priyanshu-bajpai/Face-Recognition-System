# opencv-test
# Face-Recognition-System
Face recognition system built using C++ for PCA using opencv librabries and then classification done using k-NN in python 


pca.cpp -

This file contains code for implementing PCA on the training data and creating 15 eigenvfaces and then weight vectors for each of the image which is fed to the code.
(total of 75 images) 5 images per person for 15 different persons have been fed for creating eigenfaces.

knn.py :-
 this file contains classification algorithm . ie K nearest neighbours. 


 Steps :
 1) We have already selected 75 images (5 per class ) from the database and fed to the code.
 2) Run the c++ code pca.cpp , it generates 15, 1 by 10304 column matrix of eigen faces
    stored in the files eigen”x”.txt inside the dataset folder, x from 1 to 15.This has already been done.

 3) It also generates a list of weight vectors, each of dimension 1by15 which stores the weight of the 75 images corresponding to each eigen faces, 
 and name of class of the person, this result is stored inside weight.txt, located inside dataset/weights folder.

4)Run the command python knn.py, to see the output of the testing. 

5)knn.py, weight vectors of first four images of a person are fed to this file for training, the 5th image is used for testing, 
we get incorrect classification in case of only two tests out of 15, hence giving a total accuracy of approx 85%. 

