#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <fstream>
#include <sstream>
# include <iostream>
# include <string>
# include <vector>

using namespace cv;
using namespace std;

/*
1. First time you run the code uncomment the code for putting the eigenfaces into the file.....{line 219 to 237}
2. This will generate a file inside the dataset folder, then you will have to manually delete the 2 sqaure brackets
3. From inside the 15 files for the code to run further ......sorry for this trouble..
4. Do not forget to change the pathname wherever required to 
5. you will need to download opencv for c++,  watch this video for help (only for mac users)- https://www.youtube.com/watch?v=U49CVY8yOxw
    similar videos for windows and linux are available
*/


//Normalizes a given image into a value range between 0 and 255.
    Mat norm_0_255(const Mat& src)
{
// Create and return normalized image:
    Mat dst;
    switch(src.channels()) {
        case 1:
            cv::normalize(src, dst, 0, 255, NORM_MINMAX, CV_8UC1);
            break;
        case 3:
            cv::normalize(src, dst, 0, 255, NORM_MINMAX, CV_8UC3);
            break;
        default:
            src.copyTo(dst);
            break;
    }
    return dst;
}

//Converts the images given in src into a row matrix.
Mat asRowMatrix(const vector<Mat>& src, int rtype, double alpha = 1, double beta = 0){
    
//Number of samples:
    size_t n = src.size();
    
//Return empty matrix if no matrices given:
    if(n == 0)
        return Mat();
    
//dimensionality of (reshaped) samples
    size_t d = src[0].total();
// Create resulting data matrix:
    Mat data (n, d, rtype);
    
// Now copy data:
    for(int i = 0; i < n; i++) {
        if(src[i].empty()) {
            string error_message = format("Image number %d was empty, please check your input data.", i);
            CV_Error(CV_StsBadArg, error_message);
        }
// Make sure data can be reshaped, throw a meaningful exception if not!
        if(src[i].total() != d) {
            string error_message = format("Wrong number of elements in matrix #%d! Expected %d was %d.", i, d, src[i].total());
            CV_Error(CV_StsBadArg, error_message);
        }
        Mat xi = data.row(i);
// Make reshape happy by cloning for non-continuous matrices:
        if(src[i].isContinuous()) {
            src[i].reshape(1, 1).convertTo(xi, rtype, alpha, beta);
        } else {
            src[i].clone().reshape(1, 1).convertTo(xi, rtype, alpha, beta);
        }
    }
    return data;
}


int main(int argc, const char *argv[])
{
    vector<Mat> db;
    
    string prefix = "face_rec/";
    
    db.push_back(imread(prefix + "s1/1.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s1/2.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s1/3.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s1/4.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s1/5.pgm", IMREAD_GRAYSCALE));
    
    db.push_back(imread(prefix + "s2/1.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s2/2.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s2/3.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s2/4.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s2/5.pgm", IMREAD_GRAYSCALE));
    
    db.push_back(imread(prefix + "s3/1.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s3/2.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s3/3.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s3/4.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s3/5.pgm", IMREAD_GRAYSCALE));
    
    db.push_back(imread(prefix + "s4/1.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s4/2.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s4/3.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s4/4.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s4/5.pgm", IMREAD_GRAYSCALE));
    
    db.push_back(imread(prefix + "s5/1.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s5/2.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s5/3.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s5/4.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s5/5.pgm", IMREAD_GRAYSCALE));
    
    db.push_back(imread(prefix + "s6/1.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s6/2.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s6/3.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s6/4.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s6/5.pgm", IMREAD_GRAYSCALE));

    db.push_back(imread(prefix + "s7/1.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s7/2.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s7/3.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s7/4.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s7/5.pgm", IMREAD_GRAYSCALE));
    
    db.push_back(imread(prefix + "s8/1.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s8/2.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s8/3.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s8/4.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s8/5.pgm", IMREAD_GRAYSCALE));
    
    db.push_back(imread(prefix + "s9/1.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s9/2.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s9/3.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s9/4.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s9/5.pgm", IMREAD_GRAYSCALE));
    
    db.push_back(imread(prefix + "s10/1.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s10/2.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s10/3.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s10/4.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s10/5.pgm", IMREAD_GRAYSCALE));
    
    db.push_back(imread(prefix + "s11/1.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s11/2.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s11/3.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s11/4.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s11/5.pgm", IMREAD_GRAYSCALE));
    
    db.push_back(imread(prefix + "s12/1.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s12/2.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s12/3.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s1/4.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s14/5.pgm", IMREAD_GRAYSCALE));
    
    db.push_back(imread(prefix + "s13/1.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s13/2.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s13/3.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s13/4.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s13/5.pgm", IMREAD_GRAYSCALE));
    
    db.push_back(imread(prefix + "s14/1.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s14/2.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s14/3.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s14/4.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s14/5.pgm", IMREAD_GRAYSCALE));
    
    db.push_back(imread(prefix + "s15/1.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s15/2.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s15/3.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s15/4.pgm", IMREAD_GRAYSCALE));
    db.push_back(imread(prefix + "s15/5.pgm", IMREAD_GRAYSCALE));
     
    
    
    /*cout<<"Rows = "<<db[0].rows <<"columns = "<<db[0].cols<<endl;
    cout<<"Data for first matrix: \n"<<db[0]<<endl;
    cout<<db[0].total()<<endl;
    cout<<db[0].type();*/
    
    
// Build a matrix with the observations in row:
    Mat data = asRowMatrix(db, CV_32FC1);
    
// number of components to keep for the PCA:
    int num_components = 15;
    
// Performing a PCA:
    PCA pca(data, Mat(), CV_PCA_DATA_AS_ROW, num_components);
    
//copying the PCA results:
    Mat mean = pca.mean.clone();
    Mat eigenvalues = pca.eigenvalues.clone();
    Mat eigenvectors = pca.eigenvectors.clone();
    
// The mean face:
    imshow("avg", norm_0_255(mean.reshape(1, db[0].rows)));
    
// The first 'm' eigenfaces:
    imshow("pc1", norm_0_255(pca.eigenvectors.row(0)).reshape(1, db[0].rows));
    imshow("pc2", norm_0_255(pca.eigenvectors.row(1)).reshape(1, db[1].rows));
    imshow("pc3", norm_0_255(pca.eigenvectors.row(2)).reshape(1, db[2].rows));
    imshow("pc4", norm_0_255(pca.eigenvectors.row(3)).reshape(1, db[3].rows));
    imshow("pc5", norm_0_255(pca.eigenvectors.row(4)).reshape(1, db[4].rows));
    imshow("pc6", norm_0_255(pca.eigenvectors.row(5)).reshape(1, db[5].rows));
    imshow("pc7", norm_0_255(pca.eigenvectors.row(6)).reshape(1, db[6].rows));
    imshow("pc8", norm_0_255(pca.eigenvectors.row(7)).reshape(1, db[7].rows));
    imshow("pc9", norm_0_255(pca.eigenvectors.row(8)).reshape(1, db[8].rows));
    imshow("pc10", norm_0_255(pca.eigenvectors.row(9)).reshape(1, db[9].rows));
    imshow("pc11", norm_0_255(pca.eigenvectors.row(10)).reshape(1, db[10].rows));
    imshow("pc12", norm_0_255(pca.eigenvectors.row(11)).reshape(1, db[11].rows));
    imshow("pc13", norm_0_255(pca.eigenvectors.row(12)).reshape(1, db[12].rows));
    imshow("pc14", norm_0_255(pca.eigenvectors.row(13)).reshape(1, db[13].rows));
    imshow("pc15", norm_0_255(pca.eigenvectors.row(14)).reshape(1, db[14].rows));
    
    cout<<"creating files\n";
    
//storing eigen vectors into a txt files, run this for the first time you run the code, I have already made these files inside dataset folder
  //uncomment this code to store eigen faces in the file
  /*  for(int i=0;i<15;i++)
    {
        ofstream myfile;
        string str = "/users/rkbajpai/desktop/dataset/eigen";
        string extension = ".txt";
        string Result;
        stringstream convert;
        convert << i+1;
        Result = convert.str();
        str.append(Result);
        str.append(extension);
        cout<<str<<endl;
        myfile.open(str);
        Mat mat = eigenvectors.row(i);//.t();
        cout<<"Rows = "<<mat.rows <<"columns = "<<mat.cols<<endl;
        myfile<<mat;
        myfile.close();

    }
    
    cout<<"storing process complete\n";
  */
    double weight[15][75];
    
    
//calculating the values with different eigen faces;
    for(int j=0;j<15;j++)
    {
    double values[10304];
    double sum =0;
    size_t size;
//write the code here to open eigen%d.txt......
    string str = "dataset/eigen";
    string extension = ".txt";
    string Result;
    stringstream convert;
    convert << j+1;
    Result = convert.str();
    str.append(Result);
    str.append(extension);
    cout<<str<<endl;
        
    ifstream file(str);
    int i=0;
    while ( file.good() )
    {
        getline ( file, str, ',' );
        values[i] = stod(str,&size);
        //cout <<values[i]<<endl;
        i++;
    }
    
//values for jth eigen face is avialble to me...calculated the weight of each image corresponding to this matrix
       for(int k=0;k<75;k++)
        {
            sum=0;
            i = 0;
            for(int a=0;a<112;a++)
            {
                for(int b=0;b<92;b++)
                {
                    double num1 = db[k].at<uchar>(a,b);
                    //cout<<"db(0)["<<a<<"]["<<b<<"] = "<<num1<<" ";
                    double val = num1*values[i];
                    sum = sum+ val;
                    i++;
                }
            }
        cout<<endl<<"weight for "<<k+1<<" image corresponding to "<<j+1<<"th eigenface is "<<sum<<endl;
            weight[j][k] = sum;
        }

    }
   
   ofstream myfile;
   string str = "dataset/weights/weights.txt";
   myfile.open(str);
//now output the weight matrix to a file
    for(int a=0;a<75;a++){
        if((a+1)%5!=3){
       for(int b=0;b<15;b++)
           myfile<<weight[b][a]<<",";
        myfile<<(a)/5 +1<<endl;
        }
    }
    
    
// Show the images:
    waitKey(0);
    
// Success!
    return 0;
}

