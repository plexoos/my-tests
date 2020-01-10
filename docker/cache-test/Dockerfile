FROM ubuntu:18.04

WORKDIR /tmp

# Install system packages
RUN apt-get update -qq \
 && apt-get -y install g++ gcc gfortran \
 && apt-get clean \
 && rm -rf /var/lib/apt/lists/* /tmp/*
