# Multiple-Object Detection - Type A

reference :
1. [Multiple-Object Detection (1) : R-CNN](https://man-about-town.tistory.com/51)
2. [Multiple-Object Detection (2) : SPP-Net](https://man-about-town.tistory.com/52?category=735873)
3. [Multiple-Object Detection (3) : Fast R-CNN](https://man-about-town.tistory.com/54?category=735873)
4. [갈아먹는 Object Detection [1] R-CNN](https://yeomko.tistory.com/13)
5. [갈아먹는 Object Detection [2] Spatial Pyramid Pooling Network](https://yeomko.tistory.com/14?category=888201)
6. [갈아먹는 Object Detection [3] Fast R-CNN](https://yeomko.tistory.com/15)
6. [갈아먹는 Object Detection [4] Faster R-CNN](https://yeomko.tistory.com/17?category=888201)
---

Multiple Object Detection의 동작 방식은 Region Proposal과 Classification을 별도로 수행하는 2 Step 방식과 한번에 수행하는 1 Step 방식으로 크게 나뉜다.

여기서는 2 Step 방식을 정리한다.
발전 과정은 아래와 같다. 
> `R-CNN -> SPP-Net -> Fast R-CNN -> Faster R-CNN` 

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

---
## SPP-Net
기존 CNN 모델은 Input size가 (224,224) 등으로(설계된대로) 고정되어야 했음. 즉, 이미지 원본을 모델로 직접 통과시키기 어려웠다.

Input size가 고정되는 이유는 fc 레이어 때문(Conv 레이어는 Input size를 자유롭게 받을 수 있음).

SPP(Spatial Pyramid Pooling)는 Conv 레이어와 fc 레이어의 중간에서 fc 레이어가 받아야 하는 고정된 input size로 vector 크기를 변환시켜주는 역할을 한다.

### 1. CNN
Conv layer에서 `selective search`를 수행한다.

### 2. SPP
`selective search` 결과를 고정된 크기로 반환시켜준다. 즉, 고정된 크기의 `feature vector`를 추출한다.

### 3. Fully Connected Layer
`feature vector`를 1차원 벡터로 펼친다.

### 4. SVM(Support Vector Machine)
이미지 클래스별로 이진 분류를 수행한다.

### 5. Bounding Box Regressor
Linear Regression 모델을 통해 box 결과값을 더 정교하게 교정한다.

---
## Fast R-CNN
Feature extraction(CNN 수행), Classification, Bounding Box Regression까지 모두 하나의 모델에서 학습시키는 컨셉

### 1. CNN
전체 이미지를 Pre-trained CNN에 통과시켜 `selective search`과정을 통해 Feature Map을 추출한다. 

### 2. RoI Pooling
`selective search`를 통해 찾은 각각의 RoI에 대해 RoI Pooling을 수행하여 고정된 크기의 `feature vector`를 추출한다.

### 3. Fully Connected Layer
RoI Pooling을 통해 얻은 `feature vector`를 Fully Connected Layer에 통과시켜 2개의 브런치로 나눈다.

### 4-1. Branch (1) - Softmax
1개 브런치는 Softmax 결과값으로 Classification을 수행한다.

### 4-2. Branch (2) - Bounding Box Regression
다른 1개 브런치는 `selective search`로 찾은 박스의 위치를 더 정확하게 조정한다.

---
## Faster R-CNN
Region Proposal Network를 사용한 방식이다. 즉, 기존의 Network 앞단에서 RoI를 계산하던 `selective search`를 Network 안으로 끌고와서 수행하는 end-to-end 모델이다. Network 안에서 RoI 계산을 수행하므로 모든 모델이 GPU 위에서 돌아갈 수 있는 환경이다.

### 1. CNN
전체 이미지를 입력받아 Feature Map을 추출한다.

### 2. Region Proposal Network(RPN) - intermediate layer
CNN에서 추출된 Feature Map을 (height, width, channel)로 받아 3x3 Conv 레이어를 통과시키고 padding을 1(same)로 설정하여 (height, width)를 보존한다. 그 결과 (height, width, 256) 또는 (height, width, 512) 형태의 두 번째 Feature Map을 반환한다.

### 3. Fully Convolution Network
두 번째 Feature Map을 입력받아 2개의 1x1 Conv 레이어를 통과시킨다. 하나는 Classification, 다른 하나는 Bounding Box Regression 목적이다.

### 4-1. Branch (1) - Classification x softmax
채널은 18(2x9)로 받아서(1x1 Conv) (height, width, 18) 크기의 Feature Map을 반환한다. 이 값을 reshape 하여 softmax를 적용한다.

### 4-2. Branch (2) - Bounding Box Regression
채널은 36(4x9)로 받아서(1x1 Conv) Regression을 수행한다.

### 5. Non-Maximum-Suppression
Classification으로 얻은 확률 값을 정렬 후, 높은 순으로 K개의 앵커를 추려내고 Bounding Box Regression을 수행한다. 최종적으로 Non-Maximum-Suppression을 통해 RoI를 구한다.
