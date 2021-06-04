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
The 