FROM ubuntu:18.04

ARG MYARG

WORKDIR /tmp

COPY packages.ubuntu5 /tmp/packages
COPY packages.ubuntu /tmp/packages
COPY packages.${MYARG} /tmp/packages
