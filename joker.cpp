#include "joker.h"
#include "time.h"
#include "random"


void FiftyFiftyJoker::evalQuest(frage q) {

    srand (time(NULL));

    // dont look at this code
    if (q.ar == "a") {
        a = 0.5;

        switch(rand() % 3) {
        case 0:
            b = 0.5;
            break;
        case 1:
            c = 0.5;
            break;
        case 2:
            d = 0.5;
            break;
        }
    } else if (q.ar == "b") {
        switch (rand() % 3) {
        case 0:
            a = 0.5;
            break;
        case 1:
            c = 0.5;
            break;
        case 2:
            d = 0.5;
            break;
        }
        b = 0.5;
    } else if (q.ar == "c") {
        switch(rand() % 3) {
        case 0:
        a = 0.5;
        break;
        case 1:
        b = 0.5;
        break;
        case 2:
        d = 0.5;
        break;
        }
        c = 0.5;
    } else {
        switch(rand() % 3) {
        case 0:
            a = 0.5;
            break;
        case 1:
            b = 0.5;
            break;
        case 2:
            c = 0.5;
            break;
        }
        d = 0.5;
    }
}

void AudJoker::evalQuest(frage q) {
    // dont look at this code
    if (q.ar == "a") {
        a = 0.6;

        b = 0.08;
        c = 0.2;
        d = 0.12;
    } else if (q.ar == "b") {
        b = 0.56;

        a = 0.38;
        c = 0.05;
        d = 0.01;
    } else if (q.ar == "c") {
        c = 0.48;

        a = 0.45;
        b = 0.04;
        c = 0.03;
    } else {
        d = 0.27;

        a = 0.24;
        b = 0.23;
        c = 0.26;
    }
}

void PhoneJoker::evalQuest(frage q) {
    // dont look at this code
    if (q.ar == "a") {
        if (rand() % 100 > 75) {
            switch(rand() % 3) {
            case 0:
                b = 1;
                break;
            case 1:
                c = 1;
                break;
            case 2:
                d = 1;
                break;
            }
        } else {
            a = 1;
        }
    } else if (q.ar == "b") {
        if (rand() % 100 > 75) {
            switch(rand() % 3) {
            case 0:
                a = 1;
                break;
            case 1:
                c = 1;
                break;
            case 2:
                d = 1;
                break;
            }
        } else {
            b = 1;
        }
    } else if (q.ar == "c") {
        if (rand() % 100 > 75) {
            switch(rand() % 3) {
            case 0:
                a = 1;
                break;
            case 1:
                b = 1;
                break;
            case 2:
                d = 1;
                break;
            }
        } else {
            c = 1;
        }
    } else {
        if (rand() % 100 > 75) {
            switch(rand() % 3) {
            case 0:
                a = 1;
                break;
            case 1:
                b = 1;
                break;
            case 2:
                c = 1;
                break;
            }
        } else {
            d = 1;
        }
    }
}
