FROM gcc:latest

WORKDIR usr/src/ex1

COPY ./src/ .

RUN g++ -o ex1 ./main.cpp AddURL.cpp ArgsHandler1.cpp BloomFilter2.cpp FalsePositive.cpp Flow.cpp HashGenerator2.cpp ICommand.cpp URLsHandler1.cpp


CMD ["./ex1"]


