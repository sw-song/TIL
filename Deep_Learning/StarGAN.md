# StarGAN - Basic Concept

reference :
1. [github/clovaai/stargan-v2](https://github.com/clovaai/stargan-v2)
2. [github/yunjey/stargan](https://github.com/yunjey/stargan)
3. [[코드리뷰]StarGAN](https://oranz.tistory.com/48?category=927658)
4. [도메인과 스타일, 모두 잡았다! StarGAN v2](https://comlini8-8.tistory.com/13)
5. [[논문리뷰]StarGAN:Unified Generative Adversarial Networks for Multi-Domain Image-to-Image Translation](https://oranz.tistory.com/42?category=927658)
6. [StarGAN:Unified Generative Adversarial Networks for Multi-Domain Image-to-Image Translation](https://arxiv.org/pdf/1711.09020.pdf)
---

하나의 모델(GAN)이 하나의 도메인(특정 스타일)에 대해서만 학습하는 것이 아닌 여러 도메인을 한번에 학습하여 결과적으로 단일 모델만으로 다양한 스타일의 이미지를 생성해내도록 하는 컨셉이다.

![image](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2Fqjzh4%2FbtqCOAc5w7c%2FslpZlDqQNCQC7eB9COMtcK%2Fimg.png)

## (a) Training the discriminator
D learns to distinguish between real and fake images and `classify the real images to its corresponding domain.`
- 기존 GAN의 D(Discriminator)가 1차적으로 input 데이터를 받고 학습하는 방식에 더해 도메인을 동시에 분류한다.

## (b) Original-to-target domain
G takes in as input both the image and `target domain label` and generates an fake image. The target domain label is spatially replicated and concatenated with the input image.
- G(Generator)는 모방할 이미지(real image)와 One-Hot-Encoding 된 Target 도메인(목표로 하는 도메인)의 Vector를 input 값으로 받아 가짜 이미지(fake image)를 생성한다.

## (c) Target-to-original domain
G tries to reconstruct the original image from the fake image given the original domain label.
- (b)에서 생성한 가짜 이미지(fake image)와 Original 도메인(진짜 이미지의 도메인)의 Vector를 input 값으로 받아 기존 이미지(Original image, 진짜 이미지)를 재구성한다(생성한다).

## (d) Fooling the discriminator
G tries to generate images indistinguishable from real images and classifiable as target domain by D.
- G(Generator)는 진짜 이미지와 구별하기 어려운 이미지를 생성(generate, reconstruct)한다. 또한 생성해낸 이미지를 D(Discriminator)가 목표로하는 target domain으로 분류해내도록 한다.

