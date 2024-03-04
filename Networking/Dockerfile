FROM gcc:latest
COPY . /Networking
WORKDIR /Networking/
RUN gcc test.c Server.c
EXPOSE 80
CMD ["./a.out"]