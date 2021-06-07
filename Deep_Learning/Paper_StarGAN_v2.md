# [StarGAN v2: Diverse Image Synthesis for Multiple Domains](https://arxiv.org/pdf/1912.01865.pdf)
---

## Abstract
Experiments on `CelebA-HQ` and a new `animal faces dataset (AFHQ)` validate our superiority in terms of visual quality, diversity, and scalability.

## 1. Introduction
An ideal image-to-image translation method should be able to synthesize images considering the diverse styles in each domain.
- `domain` means makeup, beard, and hairstyle etc.

StarGAN v2 has a scalable approach that can generate **diverse** images across **multiple domains**. And StarGAN v2 replace domain label with domain specific style code that can represent diverse `styles` of a specific `domain`. For this, two module is proposed.
- A Mapping Network : learns to transform random Gaussian noise into a style code
- A Style Encoder : learns to extract the style code from a given reference image

Considering multiple domains, both modules have `multiple output branches`, each of which provides style codes for a specific domain.

## 2. StarGAN v2
1. framework
2. its training objective functions.

### 2-1. Framework
```
X : sets of images
Y : possible domains
```
The goal of training is to train a **single** generator `G` that can generate **diverse** images of each domain y that corresponds to the image x.
- **Generator** : Generator G translates an input image x into an output image G(x,s) reflecting a `domain-specific style code s`, which is provided either by the `mapping network F` or by the `style encoder E``
- **Mapping Network** : Given a latent code z and a domain y, the Mapping Network F generates a style code s = F_y(z). F can produce diverse style codes by sampling the latent vector z(in Z) and the domain y(in Y) randomly. This multi-task architecture allows F to efficiently and effectively learn style representations of all domains.
- **Style Encoder** : Given an image x and its corresponding domain y, the Encoder E extracts the style code s = E_y(x) of x. Style Encoder E can produce diverse style codes using different reference images. This allows G to synthesize an output image reflecting the style s of a reference image x.
- **Discriminator** : Discriminator D is a multi-task discriminator, which consists of multiple output branches. Each branch D_y learns a binary classification determining whether an image x is a real image of its domain y or a fake image G(x,s) produced by G.



![image](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2Fcv0Rdo%2FbtqCSXrGFiK%2FnpcOMdpkHvRY2KSjFaDkq0%2Fimg.png)

### 2-2. Training Objectives
Given an image x(in X) and its original domain y(in Y), we train the framework using the following objectives.
- **Adversarial Objective** : During training, we sample a latent code z(in Z) and a target domain y~(in Y) randomly, and generate a target style code s~ = F_y~(z). The generator G takes an image x and s~ as inputs and learns to generate an output image G(x,s~) via an `adversarial loss`.
- **Style Reconstruction** : We train a **single** encoder E to encourage diverse outputs for multiple domains.
- **Style Diversification** : Maximizing the regularization term forces G to explore the image space and discover meaningful style features to generate diverse images.
- **Preserving source characteristics** : To guarantee that the generated image G(x,s~) properly preserves the domain invariant characteristics (e.g. pose) of its input image x, we employ the cycle consistency loss.
