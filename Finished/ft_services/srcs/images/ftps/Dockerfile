FROM alpine:latest

EXPOSE 21 20 30100-30103
ARG KIP
ENV MINIKUIP=$KIP

RUN apk update && apk upgrade
RUN apk add vsftpd

RUN echo password > pass.txt && echo password >> pass.txt
RUN adduser ftp_user < pass.txt && rm -rf pass.txt

RUN mkdir /home/ftp_user/ftp_folder && touch /home/ftp_user/ftp_folder/test.txt
RUN chmod -R 766 /home/ftp_user && chown ftp_user -R /home/ftp_user

ADD ./data/localhost.cert /localhost.cert
ADD ./data/localhost.key /localhost.key
ADD ./data/vsftpd.conf /etc/vsftpd.conf
RUN echo pasv_address=${MINIKUIP} >> /etc/vsftpd.conf

#CMD tail -f /dev/null
CMD vsftpd
