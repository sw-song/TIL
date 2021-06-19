# GAN : Unpaired Image to Image Translation

reference:
1. [Youtube | [MODUCON 2019] 보다 유연한 이미지 변환을 하려면 - 이광희](https://www.youtube.com/watch?v=rHDa_fEd_0Q)
2. [PPT | 보다 유연한 이미지 변환을 하려면 - 이광희](http://moducon.kr/wp/wp-content/uploads/2020/02/%E1%84%8B%E1%85%B5%E1%84%80%E1%85%AA%E1%86%BC%E1%84%92%E1%85%B4_ModuCon.pdf) 
---


### 1. Unimodal(one-to-one) Translation
> 하나의 도메인, 하나의 스타일에 대한 변환
- Type A : `Cycle Consistency Loss`
    - CycleGAN (ICCV, 2017)
    - DiscoGAN (ICCV, 2017)

- Type B : `Shared Latent space Assumption`
    - UNIT (NIPS,2017)

### 2. Multi-modal Tranlation
> 하나의 도메인 내에서 다양한 스타일을 표현

`Partially Shared Latent Space`

`Feature Disentanglement`

- MUNIT (ECCV, 2018)
- DRIT (ECCV, 2018)

### 3. Multi-domain Tlanslation
> 다양한 도메인을 표현

`Domain Label` 

`Unified Structure`

- StarGAN (CVPR, 2018)

### 4. Multi-mapping Translation (Multi-modal + Multi-domain)
> 다양한 도메인을 표현하고 동시에 각 도메인마다 다양한 스타일까지 함께 표현

`Unified Style Encoder`
- DRIT++ (arXiv, 2019)
- DMIT (Neurips, 2019)
- SDIT (ICM, 2019)
- StarGAN v2 (arXiv, 2019)