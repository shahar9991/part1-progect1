FROM gcc:latest

WORKDIR usr/src/ex1

COPY ./src/ .

RUN g++ -o my_program Flow.cpp ArgsHandler.cpp URLsHandler.cpp sockets.cpp HashGenerator.cpp BloomFilter.cpp FalsePositive.cpp IsBlackListed.cpp AddURL.cpp -pthread
EXPOSE 54321

CMD ["./my_program"]


