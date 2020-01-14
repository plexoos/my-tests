FROM ubuntu:18.04

ARG MYARG

WORKDIR /tmp

RUN apt-get update -qq \
 && apt-get -y install curl \
 && apt-get clean


# Get STAR software
RUN curl -s -L https://github.com/star-bnl/star-sw/archive/master.tar.gz  | tar -xz -C /tmp

## Install ROOT5
RUN curl https://root.cern.ch/download/root_v5.34.38.source.tar.gz | tar -xz -C /tmp


RUN apt-get update -qq \
 && apt-get -y install patch \
 && apt-get clean

RUN cd /tmp/root && patch -p1 < /tmp/star-sw-master/patches/root_v5.34.38.patch
