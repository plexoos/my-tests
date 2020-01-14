FROM ubuntu:18.04

ARG MYARG

WORKDIR /tmp

# Get STAR software
ADD https://api.github.com/repos/star-bnl/star-sw/commits/master star-sw-ref.json
RUN curl -s -L https://github.com/star-bnl/star-sw/archive/master.tar.gz  | tar -xz -C /tmp

# Install ROOT5
RUN curl https://root.cern.ch/download/root_v5.34.38.source.tar.gz | tar -xz -C /tmp \
 && mv /tmp/root /tmp/root-5-34-38 && cd /tmp/root-5-34-38 \
 && patch -p1 < /tmp/star-sw-master/patches/root_v5.34.38.patch
