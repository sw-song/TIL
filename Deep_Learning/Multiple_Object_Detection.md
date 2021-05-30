# Multiple-Object Detection 

reference :
1. [Multiple-Object Detection (1) : R-CNN](https://man-about-town.tistory.com/51)
2. [Multiple-Object Detection (2) : SPP-Net](https://man-about-town.tistory.com/52?category=735873)
3. [Multiple-Object Detection (3) : Fast R-CNN](https://man-about-town.tistory.com/54?category=735873)
4. [갈아먹는 Object Detection [1] R-CNN](https://yeomko.tistory.com/13)
5. [갈아먹는 Object Detection [2] Spatial Pyramid Pooling Network](https://yeomko.tistory.com/14?category=888201)
6. [갈아먹는 Object Detection [3] Fast R-CNN](https://yeomko.tistory.com/15)
6. [갈아먹는 Object Detection [4] Faster R-CNN](https://yeomko.tistory.com/17?category=888201)
---


## R-CNN

### 1. Region Proposal
a. `selective search` 과정을 통해 `image segmentation`을 수행한다.
b. `image segmentation`을 통해 `object detection`(multiple object, 약 2000개의 box)을 수행한다.
c. 2000개의 box들은 227x227로 resize(warp)

### 2. Feature Extraction
a. 227x227 box들이 CNN(Image Classification, imagenet) 모델을 통과한다.
b. CNN 모델은 4096 size vector Output을 돌려준다.
c. 최종 레이어의 Output은 Object Detection Class 수 +1(배경)

### 4. Non-Maximum Suppression
2000개 박스 중 불필요한(스코어가 낮은) 박스는 모두 제거하는 과정.

동일한 물체에 여러 박스가 표시될 수 있는데, 이 때 그 물제를 가장 잘 설명하는 박스만 남긴다.

### 5. Bounding Box Regression
`Selective Search`를 통해 찾은 박스 위치는 정확하지 않기 때문에 Linear Regression 모델 학습을 통해 위치를 교정한다.