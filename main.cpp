#include <QApplication>
#include "controller.h"
#include <QList>
#include <string>
#include <QString>
#include <iostream>
#include <QMessageLogger>
#include <QDebug>

QList<frage> *quests;

void initQuests() {
    frage qa;
        qa.qw = "Peter Kreuder komponierte 1936 den Schlager Ich wollt' ich wär' ein ...?";
        qa.an1 = "a) Hund ";
        qa.an2 = "b) Huhn ";
        qa.an3 = "c) Hummer ";
        qa.an4 = "d) Huflattich ";
        qa.ar = "b";

        frage qa1;
        qa1.qw = "Wobei handelt es sich um ein Notsignal im internationalen Funkverkehr?";
        qa1.an1 = "a) Mayday";
        qa1.an2 = "b) Down Town ";
        qa1.an3 = "c) Jetset";
        qa1.an4 = "d) Flower Power ";
        qa1.ar = "a";

        frage qa2;
        qa2.qw = "Wie heißt - laut einem Maerchen der Brueder Grimm - die Schwester von Schneeweißchen?";
        qa2.an1 = "a) Fliederlila";
        qa2.an2 = "b) Maisgelb";
        qa2.an3 = "c) Rosenrot";
        qa2.an4 = "d) Kornblumenblau";
        qa2.ar = "c";

        frage qa3;
        qa3.qw = "Wer hat von Berufs wegen mit dem Spritzenhaus zu tun?";
        qa3.an1 = "a) Gärtner";
        qa3.an2 = "b) Krankenschwester";
        qa3.an3 = "c) Feuerwehrmann";
        qa3.an4 = "d) Konditor";
        qa3.ar = "c";

        frage qa4;
        qa4.qw = "Was ist die Amtssprache von Mexiko?";
        qa4.an1 = "a) Portugiesisch";
        qa4.an2 = "b) Englisch";
        qa4.an3 = "c) Französisch";
        qa4.an4 = "d) Spanisch";
        qa4.ar = "d";

        frage qa5;
        qa5.qw = "Unter welchem Namen sangen Wigald Boning und Olli Dittrich Lieder, die die Welt nicht braucht?";
        qa5.an1 = "a) Die Behaemmerten";
        qa5.an2 = "b) Die Abgedrehten";
        qa5.an3 = "c) Die Doofen";
        qa5.an4 = "d) Die Irren";
        qa5.ar = "c";

        frage qa6;
        qa6.qw = "Was ist ein Rebus?";
        qa6.an1 = "a) Kreditinstitut";
        qa6.an2 = "b) Werkzeug";
        qa6.an3 = "c) Weinstock";
        qa6.an4 = "d) Bilderraetsel";
        qa6.ar = "d";

        frage qa7;
        qa7.qw = "Wie nennt man von Gletschern transportierten Gesteinsschutt?";
        qa7.an1 = "a) Moraene";
        qa7.an2 = "b) Muraene";
        qa7.an3 = "c) Morelle";
        qa7.an4 = "d) Murnau";
        qa7.ar = "a";

        frage qa8;
        qa8.qw = "Welches deutsche Fuerstenhaus organisierte bis ins 19. Jahrhundert die kaiserliche Reichspost?";
        qa8.an1 = "a) Fuerstenberg";
        qa8.an2 = "b) Schaumburg";
        qa8.an3 = "c) Hohenlohe";
        qa8.an4 = "d) Thurn und Taxis";
        qa8.ar = "d";

        frage qa9;
        qa9.qw = "Wobei handelt es sich nicht um ein Insekt?";
        qa9.an1 = "a) Steckmuecke";
        qa9.an2 = "b) Wintermücke";
        qa9.an3 = "c) Grasmuecke";
        qa9.an4 = "d) Kriebelmuecke";
        qa9.ar = "c";

        frage qa10;
        qa10.qw = "Wie heißt das traditionelle Pferderennen in Siena?";
        qa10.an1 = "a) Calcio";
        qa10.an2 = "b) Palio";
        qa10.an3 = "c) Barolo";
        qa10.an4 = "d) Boccia";
        qa10.ar = "b";

        frage qa11;
        qa11.qw = "Was ist nach Mahon, dem Hauptort der Insel Menorca, benannt?";
        qa11.an1 = "a) Marone";
        qa11.an2 = "b) Mahagoni";
        qa11.an3 = "c) Marihuana ";
        qa11.an4 = "d) Mayonese";
        qa11.ar = "d";

        frage qa12;
        qa12.qw = "Welcher deutsche Boxer schlug im Juni 1952 den Ringrichter Max Pippow zu Boden?";
        qa12.an1 = "a) Peter Mueller";
        qa12.an2 = "b) Eckhard Dagge";
        qa12.an3 = "c) Bubi Scholz";
        qa12.an4 = "d) Max Schmeling";
        qa12.ar = "a";

        frage qa13;
        qa13.qw = "Wo befindet sich der Hauptsitz der UNESCO?";
        qa13.an1 = "a) Bruessel";
        qa13.an2 = "b) Paris";
        qa13.an3 = "c) London";
        qa13.an4 = "d) Helsinki";
        qa13.ar = "b";

        frage qa14;
        qa14.qw = "Mit wem stand Edmund Hillary 1953 auf dem Gipfel des Mount Everest?";
        qa14.an1 = "a) Nasreddin Hodscha";
        qa14.an2 = "b) Nursay Pimsorn";
        qa14.an3 = "c) Tenzing Norgay";
        qa14.an4 = "d) Abrindranath Singh";
        qa14.ar = "c";

        quests = new QList<frage>();
        quests->append(qa);
        quests->append(qa1);
        quests->append(qa2);
        quests->append(qa3);
        quests->append(qa4);
        quests->append(qa5);
        quests->append(qa6);
        quests->append(qa7);
        quests->append(qa8);
        quests->append(qa9);
        quests->append(qa10);
        quests->append(qa11);
        quests->append(qa12);
        quests->append(qa13);
        quests->append(qa14);

}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QMessageLogger().info() << "Starting Game";
    initQuests();
    Controller c(&a);
    c.startGame(quests);


    return a.exec();
}
