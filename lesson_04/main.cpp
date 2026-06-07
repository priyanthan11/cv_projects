#include <openCV2/opencv.hpp>
#include <iostream>

int main()
{

  cv::Mat image = cv::imread("C:/___C++/1. C++/cv_projects/lesson_03/test.jpg");
  if(image.empty())
  {
    std::cout << "Could not load the image." << std::endl;
    return -1;
  }
  cv::Mat resizedImage;
  cv::resize(image, resizedImage, cv::Size(800,600));
  // PIXEL ACCESS
  cv::Vec3b pixel = resizedImage.at<cv::Vec3b>(100,100);
  std::cout<< "Pixel at (100,100): "
            << "B="<<(int)pixel[0]<< " "
            << "G="<<(int)pixel[1]<< " "
            << "R="<<(int)pixel[2]<< std::endl;
  
  // BLURING
  cv::Mat blurredImage;
  cv::GaussianBlur(resizedImage, blurredImage, cv::Size(15,15),0);

  // EDGE DETECTION
  cv::Mat gray, edges;
  cv::cvtColor(resizedImage,gray, cv::COLOR_BGR2GRAY);
  cv::Canny(gray,edges,10,50);

  // DISPPLAY
  cv::imshow("Original Image",resizedImage);
  cv::imshow("Blurred Image",blurredImage);
  cv::imshow("Edges", edges);

  cv::waitKey(0);
  cv::destroyAllWindows();
  return 0;
}