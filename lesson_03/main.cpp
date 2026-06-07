#include <openCV2/opencv.hpp>
#include <iostream>

int main()
{
  
  cv::Mat image = cv::imread("C:\\___C++\\1. C++\\cv_projects\\lession_02\\test.jpg");
  if(image.empty())
  {
    std::cout << "Error: Could not find the image." <<std::endl;
    return -1;
  }

  // Resize
  cv::Mat resized;
  cv::resize(image,resized,cv::Size(640,400));

  std::cout << "Original Size: " <<image.cols << "x" << image.rows << std::endl;
  std::cout << "Resized Size:" <<resized.cols << "x" << resized.rows << std::endl;

  // Crop
  cv::Rect roi(3700, 2200, 500, 500); // x,y,width,height
  cv::Mat cropped = image(roi);

  // Display
  cv::imshow("Original" ,image);
  cv::imshow("Resized" ,resized);
  cv::imshow("Cropped" ,cropped);

  cv::waitKey(0); // Wait indefinitely until a key is pressed
  cv::destroyAllWindows();
  return 0;
}