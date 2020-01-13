FROM ubuntu:18.04

ARG MYARG

WORKDIR /tmp

COPY Dockerfile /tmp/MyDockerfile4
COPY Dockerfile /tmp/MyDockerfile3
COPY Dockerfile /tmp/MyDockerfile2
COPY Dockerfile /tmp/MyDockerfile
COPY Dockerfile /tmp/
COPY packages.ubuntu5 /tmp/packages
COPY packages.ubuntu /tmp/packages
COPY packages.${MYARG} /tmp/packages
