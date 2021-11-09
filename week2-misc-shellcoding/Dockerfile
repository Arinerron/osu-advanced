FROM python:3.7-buster

RUN apt-get update -yqq && apt-get install -y \
    lib32z1 xinetd \
 && rm -rf /var/lib/apt/lists/*

RUN useradd -m ctf

WORKDIR /

COPY ./ctf.xinetd /etc/xinetd.d/ctf
COPY ./start.sh /start.sh
COPY ./flag.txt /flag.txt
COPY ./main.py /main.py
RUN echo "Blocked by ctf_xinetd" > /etc/banner_fail

RUN chmod +x /start.sh

RUN chown root:ctf /main.py flag.txt && \
    chmod 750 /main.py

CMD ["/start.sh"]

EXPOSE 9999
