#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv) {
//Mat的构建,使用0，0，255填充
  Mat M(100,100, CV_8UC3, Scalar(0,0,255));
//cout 矩阵只能对两维使用
//  cout << "M = " << endl << " " << M << endl << endl;
//copy 操作，只会copy header和指向矩阵的指针，不会复制数据
  Mat B(M);
  Mat C = M;
//可以同时复制数据
  Mat F = M.clone();
  Mat G;
  M.copyTo(G);
//获取数据中的一部分ROI
  Mat D (M, Rect(10, 10, 10, 10) ); // using a rectangle
  Mat N = M(Range::all(), Range(1,3)); // using row and column boundaries
  cout << "D = " << endl << " " << D << endl << endl;
  cout << "N = " << endl << " " << N << endl << endl;
//使用create函数构建Mat,size如果和旧的保持一致，不会重新分配内存
  M.create(100,100, CV_8UC(1));
  cout << "M = " << endl << " " << M << endl << endl;
//创建多维矩阵，指定3维，接着是各维度的大小
  int sz[3] = {2,2,2};
  Mat L(3,sz, CV_8UC(1), Scalar::all(0));
//创建单位矩阵，全1矩阵和全0矩阵
  Mat E = Mat::eye(4, 4, CV_64F);
  cout << "E = " << endl << " " << E << endl << endl;
  Mat O = Mat::ones(2, 2, CV_32F);
  cout << "O = " << endl << " " << O << endl << endl;
  Mat Z = Mat::zeros(3,3, CV_8UC1);
  cout << "Z = " << endl << " " << Z << endl << endl;
//

//读取图片,BGR,并显示
  Mat pic = imread("/home/fyx/git-workspace/OpenCV/opencv/image/lena.jpg",IMREAD_COLOR);
  namedWindow("image", WINDOW_AUTOSIZE);
  imshow("image",pic);
  waitKey(0);
  return 0;
}
