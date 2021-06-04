# StarGAN v2 - Basic Concept

reference :
1. [github/clovaai/stargan-v2](https://github.com/clovaai/stargan-v2)
2. [github/yunjey/stargan](https://github.com/yunjey/stargan)
3. [StarGAN v2: Diverse Image Synthesis for Multiple Domains](https://arxiv.org/pdf/1912.01865.pdf)
4. [도메인과 스타일, 모두 잡았다! StarGAN v2](https://comlini8-8.tistory.com/13)
---
기존 `StarGAN`는 하나의 모델로 하나의 도메인에 대해 학습, Generate하는 것이 아닌, 하나의 모델로 다양한 도메인을 표현해낼 수 있었다면 `StarGAN v2`는 이에 더해 여러 도메인을 결합하여 동시에 표현해낼 수 있다.

예를 들어, 기존의 `StarGAN`은 입력받은 하나의 이미지가 서로 다른 다양한 도메인을 표현하도록 가짜 이미지를 생성해낸다.
![image](https://github.com/yunjey/stargan/raw/master/jpg/main.jpg)
>출처 : [StarGAN - Official/README](https://github.com/yunjey/stargan/blob/master/README.md)

반면, `StarGAN v2`는 입력 받은 하나의 이미지가 몇가지 도메인을 동시에 표현하도록 가짜 이미지를 생성해낸다.
![image](https://github.com/clovaai/stargan-v2/raw/master/assets/teaser.jpg)
>출처 : [StarGAN v2 - Official/README](https://github.com/clovaai/stargan-v2/blob/master/README.md)

이처럼 `StarGAN v2`에서는 입력 받은 이미지에서 표정(눈,코,입 위치)을 가져와 그러한 표정을 지닌채로 남성(하나의 도메인)이면서 수염(또 다른 도메인)이 있는 이미지를 만들어낼 수 있다.

모델의 컨셉은 아래와 같다.

![image](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2Fcv0Rdo%2FbtqCSXrGFiK%2FnpcOMdpkHvRY2KSjFaDkq0%2Fimg.png)

## (a) Generator
The generator translates an input image into an output image reflecting the domain-specific style code.
- G(Generator)는 이미지(X-metrics)와 스타일(s-vector)을 input으로 받고 목표로 하는 도메인이 반영된 이미지를 반환한다.

## (b) Mapping network
The mapping network transforms a latent code into style codes for multiple domains, one of which is randomly selected during training.
- F(Mapping Network)는 랜덤으로 생성되는 `latent vacter 'z'`를 input으로 받고 주어진 도메인을 모두 커버하는 `style vector 's'`를 반환한다.

## (c) Style encoder
The style encoder extracts the style code of an image, allowing the generator to perform reference-guided image synthesis.
- E(Style Encoder)는 이미지(X-metrics)를 input으로 받고 주어진 도메인에 해당하는 `style vector 's'`를 반환한다.

## (d) Discriminator
The discriminator distinguishes between real and fake images from multiple domains.
- D(Multiple output Discriminator / Multitask Discriminator)는 각 도메인을 담당하는 branch들로 구성되어 있으며 각 branch는 G(Generator)가 생성해낸 G(x,s) 이미지를 input으로 받고 이진분류(sigmoid)를 통해 1 혹은 0을 돌려준다. 1이 반환되었다면 G(x,s)가 진짜이미지처럼 잘 생성된 것을 의미한다.


