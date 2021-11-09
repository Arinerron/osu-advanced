FROM ubuntu:18.04

RUN apt-get update -y && apt-get install -y \
    lib32z1 xinetd \
 && rm -rf /var/lib/apt/lists/*

RUN useradd -m ctf

WORKDIR /

COPY ./ctf.xinetd /etc/xinetd.d/ctf
COPY ./start.sh /start.sh
RUN echo "Blocked by ctf_xinetd" > /etc/banner_fail

RUN chmod +x /start.sh

COPY ./bin/aaron-debugger /aaron-debugger
COPY ./bin/flag.txt /flag.txt

RUN chown root:ctf /aaron-debugger /flag.txt && \
    chmod 750 /aaron-debugger && \
    chmod 740 /flag.txt

CMD ["/start.sh"]

ENV LANG C.UTF-8

EXPOSE 9999
