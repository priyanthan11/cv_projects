#include <Opencv2/opencv.hpp>
#include <iostream>

int main()
{
  cv::Mat image = cv::imread("C:/___C++/1. C++/cv_projects/lesson_05/test.jpg");
  if(image.empty())
  {
    std::cout << "Could not load the image." <<std::endl;
    return -1;
  }
  //cv::resize(image,image,cv::Size(800,600));
  // PREPARE
  cv::Mat gray, edges;
  cv::cvtColor(image,gray,cv::COLOR_BGR2GRAY);
  cv::GaussianBlur(gray,gray,cv::Size(3,3),0);
  cv::Canny(gray,edges,25,25);
  cv::dilate(edges,edges,cv::Mat(),cv::Point(-1,-1),2); // <= DILATE TO CONNECT EDGES
  // FIND CONTOURS
  std::vector<std::vector<cv::Point>> contours;
  std::vector<cv::Vec4i> hierarchy;
  cv::findContours(edges,contours,hierarchy,cv::RETR_EXTERNAL,cv::CHAIN_APPROX_SIMPLE);

  std::cout << "Contours found: " <<contours.size() << std::endl;

  // FIND AND DRAW
  cv::Mat output = image.clone();
  int drawn = 0;

  for(int i{0}; i <contours.size();++i)
  {
    double area = cv::contourArea(contours[i]);
    if(area > 1000)
    {
      std::cout << "Contour " << i << " area: " << area << std::endl;
      cv::drawContours(output,contours,i,cv::Scalar(0,255,0),2);
      
      // DRAW BOUNDING BOX AROUND EACH CONTOUR
      cv::Rect boundingBox = cv::boundingRect(contours[i]);
      cv::rectangle(output,boundingBox,cv::Scalar(255,0,0),2);

      // Label with area 
      cv::putText(output, std::to_string((int)area), 
                  cv::Point(boundingBox.x, boundingBox.y - 5), 
                  cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255,0,0), 1);

      drawn++;
    }
  }

  std::cout << "Contours drawn: " << drawn << std::endl;
  
  // DRAW SHAPES
  // cv::rectangle(output,cv::Point(50,50),cv::Point(300,200),cv::Scalar(0,0,255),3);
  
  // cv::circle(output,cv::Point(500,500),80,cv::Scalar(0,255,255),3);

  // cv::putText(output, "Lesson 05", cv::Point(50,400), cv::FONT_HERSHEY_SIMPLEX,2.0,cv::Scalar(255,0,0),3);

  // DISPLAY
  cv::imshow("Edges ",edges);
  cv::imshow("Output", output);

  cv::waitKey(0);

  return 0;
}