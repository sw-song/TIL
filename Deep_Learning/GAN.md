# GAN - Basic Concept

reference :
1. [GAN의 활용 사례와 발전 방향](https://www.samsungsds.com/kr/insights/Generative-adversarial-network-AI-3.html)
2. [ConditionalGAN(CGAN)](https://wiserloner.tistory.com/1202)
3. [생성적 적대 신경망](https://ebbnflow.tistory.com/167)
4. [논문으로 본 적대적 생성 신경망 GAN](http://scimonitors.com/toagi③-적대적-생성-신경망-gan이란/)
5. [NEVER Engineering | 1시간만에 GAN(Generative Adversarial Network) 완전 정복하기](https://tv.naver.com/v/1947034)
---
> GAN(Generative Adversarial Network)은 특정 정보를 생성(Generative)하는 항과 이와 대립(Adversarial)하는 항으로 이루어진 망(Network)을 뜻한다.

## Training
- 생성자 모델 G(Generative)는 훈련 데이터 X 분포를 흉내내도록 훈련한다
- 판별자 모델 D(Discriminator, Adversarial)는 생성자 모델 G가 생성한 데이터가 진짜인지 여부를 판별하도록 훈련한다.

## Two-Player MiniMax Game
- 판별자 모델의 훈련데이터 예측 값, 즉 D(x)의 목표치는 1이다.
- 반면, 생성자 모델이 만들어낸 샘플에 대한 예측 값, 즉 D(G(x))의 목표치는 0이다.
- 여기서 판별자 모델 D는 목표치 0에 맞게 가짜 데이터(훈련 데이터가 아닌)를 `진짜가 아니다(0)`라고 판별하도록 훈련하는 동안 생성자 모델 G는 판별자 모델 D가 가짜 데이터를 `진짜가 맞다(1)`로 판별하도록 계속해서 학습한다.
- 판별자 모델 D는 가짜 데이터(G가 생성한 이미지)를 진짜로 판별할 확률을 `최소화`하고, 생성자 모델 G는 판별자 모델 D가 가짜 데이터를 진짜로 판별할 확률을 `최대화`하도록 하는 것이다.
- 이를 두 행위자 최소최대 게임(two-player minimax game)이라 한다.
- 학습이 거듭되면서 D(G(z))가 0에서 1까지 올라갈 수 있으며, 1에 가까울 수록 가짜 여부를 판별하기 어려워진다.

## Concept Code - Naver Engineering/최윤제
```python
import torch
import torch.nn as nn

D = nn.Sequential(
    nn.Linear(784, 128), # flattend image (28*28), hidden layer 128
    nn.ReLU(),
    nn.Linear(128, 1),
    nn.Sigmoid() # classification - 0 or 1 (50%)
)

G = nn.Sequential(
    nn.Linear(100, 128), # Latent vector (100), hidden layer 128
    nn.ReLU(),
    nn.Linear(128, 784), # output == flattend image (28*28)
    nn.Tenh()
)

criterion = nn.BCELoss() # loss function

d_optimizer = torch.optim.Adam(D.parameters(), lr=0.01)
g_optimizer = torch.optim.Adam(G.parameters(), lr=0.01)

# Assume x be real images of shape (batch_size, 784)
# Assume z be random noise of shape (batch_size, 100)

while True:
    # train D
    loss = criterion(D(x), 1) + criterion(D(G(z), 0)
    loss.backward()
    d_optimizer.step()

    # train G
    loss = criterion(D(G(z)), 1)
    loss.backward()
    g_optimizer.step()
```


