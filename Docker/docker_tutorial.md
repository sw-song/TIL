# Docker Intro

reference :
1. [도커(Docker) 입문편](https://www.44bits.io/ko/post/easy-deploy-with-docker#도커docker-시작하기-우분투에서-센트os로-프로세스-실행하기)
2. [[Docker]Docker File을 이용하여 Docker Image 만들기](https://khj93.tistory.com/entry/Docker-Docker-File-작성하기-명령어)
3. [vi/vim 편집기 명령어 정리 (단축키 모음/목록)](https://iamfreeman.tistory.com/entry/vi-vim-편집기-명령어-정리-단축키-모음-목록)
---

> Tutorial : [도커(Docker) 입문편](https://www.44bits.io/ko/post/easy-deploy-with-docker#도커docker-시작하기-우분투에서-센트os로-프로세스-실행하기) 내용 중 예시 명령어 요약

도커 저장소로부터 `centos:latest` image를 받아와 아래 기본 명령어들을 경험해본다.
- docker run -it centos:latest bash
- docker ps
- docker ps -a
- docker restart
- docker attach

`ubuntu:bionic` image를 받아와 git을 설치해보고, 아래 명령어들을 통해 버전관리를 경험해본다.
- docker pull ubuntu:bionic
- docker run -it ubuntu:bionic bash
- /# git --version
- docker ps
- /# apt update
- /# apt install -y git
- /# git --version
- docker diff `process_id` | head
- docker run -it --rm ubuntu:bionic bash
- /# git --version
- /# exit
- docker commit `process(container)_id` `ubuntu:git`
- docker run -i -t ubuntu:git bash
- /# git --version
- /# exit
- docker rm `process(container)_id`
- docker rmi `image_id`

Dockerfile을 통해 도커 이미지를 만들어본다.
- midir git-from-dockerfile
- cd git-from-dockerfile
- vim Dockerfile
- ~ FROM ubuntu:bionic
- ~ RUN apt-get update
- ~ RUN apt-get install -y git
- docker built -t ubuntu:git-from-dockerfile .
- docker run -it ubuntu:git-from-dockerfile bash
- /# git --version