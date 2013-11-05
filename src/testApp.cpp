#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
//  ofSetFrameRate(1);
  gridImage.loadImage("gridsmall.png");
  gridImage.setImageType(OF_IMAGE_GRAYSCALE);
//  blurred.allocate(gridImage.width/2, gridImage.height/2, OF_IMAGE_COLOR);
//  ofSetWindowShape(gridImage.width, gridImage.height/2);
  blurred.allocate(gridImage.width, gridImage.height, OF_IMAGE_GRAYSCALE);
  ofSetWindowShape(gridImage.width*2, gridImage.height);

  unsigned char *originalPixels = gridImage.getPixels();
  unsigned char *blurredPixels = blurred.getPixels();
  int w = gridImage.width;
  int h = gridImage.height;
  int blurRadius = 1;
  float sigma = 5;
  float *gaussMatrix = getGaussianMatrix(blurRadius, sigma);
  int dimension = blurRadius * 2 + 1;
  
  
  // print out the gauss matrix:
  //
  for (int i = 0; i < dimension; i++) {
    for (int j = 0; j < dimension; j++) {
      cout << gaussMatrix[dimension * i + j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      float newValue = 0;
      for (int inneri = 0; inneri < dimension; inneri++) {
        for (int innerj = 0; innerj < dimension; innerj++) {
          int matrixX = inneri - blurRadius;
          int matrixY = innerj - blurRadius;
          int x = ofClamp(i + matrixX, 0, w-1);
          int y = ofClamp(j + matrixY, 0, h-1);
          newValue += originalPixels[y*w + x] * gaussMatrix[matrixY*dimension + matrixX];
        }
      }
      blurredPixels[j*w + i] = newValue;
    }
  }
  
  free(gaussMatrix);
  blurred.update();

}

float *testApp::getGaussianMatrix(int blurRadius, float sigma) {
  int dimension = blurRadius * 2 + 1;
  float *matrix = (float *) malloc(sizeof(float)*dimension*dimension);
  float euler = 2.71828182846;
  
  for (int i = 0; i < dimension; i++) {
    for (int j = 0; j < dimension; j++) {
      float x = i - blurRadius;
      float y = j - blurRadius;
      
      matrix[j*dimension + i] = 1/(2*PI*pow(sigma, 2)) * pow(euler, -(pow(x,2)+ pow(y,2))/(2*pow(sigma, 2)));
    }
  }
  
  float sum = 0;
  for (int i = 0; i < dimension*dimension; i++) {
    sum += matrix[i];
  }
  
  for (int i = 0; i < dimension*dimension; i++) {
    matrix[i] = matrix[i]/sum;
  }

  return matrix;
}

// malloc free
// new delete


//--------------------------------------------------------------
void testApp::update(){
//  unsigned char *originalPixels = gridImage.getPixels();
//  unsigned char *blurredPixels = blurred.getPixels();
//  int w = gridImage.width;
//  int h = gridImage.height;
//  int blurRadius = 1;
//  float sigma = 5;
//  float *gaussMatrix = getGaussianMatrix(blurRadius, sigma);
//  int dimension = blurRadius * 2 + 1;
//  
//  
//  // print out the gauss matrix:
//  //
//  for (int i = 0; i < dimension; i++) {
//    for (int j = 0; j < dimension; j++) {
//      cout << gaussMatrix[dimension * i + j] << " ";
//    }
//    cout << endl;
//  }
//  cout << endl;
//
//  for (int i = 0; i < w; i++) {
//    for (int j = 0; j < h; j++) {
//      float newValue = 0;
//      for (int inneri = 0; inneri < dimension; inneri++) {
//        for (int innerj = 0; innerj < dimension; innerj++) {
//          int matrixX = inneri - blurRadius;
//          int matrixY = innerj - blurRadius;
//          int x = ofClamp(i + matrixX, 0, w-1);
//          int y = ofClamp(j + matrixY, 0, h-1);
//          newValue += originalPixels[y*w + x] * gaussMatrix[matrixY*dimension + matrixX];
//        }
//      }
//      blurredPixels[j*w + i] = newValue;
//    }
//  }
//  
//  free(gaussMatrix);
//  blurred.update();

}

//--------------------------------------------------------------
void testApp::draw(){
//  ofBackground(0);
//  ofSetRectMode(OF_RECTMODE_CORNER);
//  gridImage.draw(0, 0, gridImage.width/2, gridImage.height/2);
//  blurred.draw(gridImage.width/2, 0, gridImage.width/2, gridImage.height/2);
//  ofSetColor(255,255,255);
  gridImage.draw(0, 0);
//  ofSetColor(255,255,255);
  blurred.draw(gridImage.width, 0);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
