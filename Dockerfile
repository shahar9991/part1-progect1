FROM gcc:latest

WORKDIR /usr/src/part1-progect1

COPY ./src/ .

RUN g++ -o part1-progect1 ./main.cpp ./bloom_filter.cpp ./inputHandler.cpp

CMD ["./part1-progect1"]
