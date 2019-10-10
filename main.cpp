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
        qa.an1 = "Hund ";
        qa.an2 = "Huhn ";
        qa.an3 = "Hummer ";
        qa.an4 = "Huflattich ";
        qa.ar = "b";

        frage qa1;
        qa1.qw = "Wobei handelt es sich um ein Notsignal im internationalen Funkverkehr?";
        qa1.an1 = "Mayday";
        qa1.an2 = "Down Town ";
        qa1.an3 = "Jetset";
        qa1.an4 = "Flower Power ";
        qa1.ar = "a";

        frage qa2;
        qa2.qw = "Wie heißt - laut einem Maerchen der Brueder Grimm - die Schwester von Schneeweißchen?";
        qa2.an1 = "Fliederlila";
        qa2.an2 = "Maisgelb";
        qa2.an3 = "Rosenrot";
        qa2.an4 = "Kornblumenblau";
        qa2.ar = "c";

        frage qa3;
        qa3.qw = "Wer hat von Berufs wegen mit dem Spritzenhaus zu tun?";
        qa3.an1 = "Gärtner";
        qa3.an2 = "Krankenschwester";
        qa3.an3 = "Feuerwehrmann";
        qa3.an4 = "Konditor";
        qa3.ar = "c";

        frage qa4;
        qa4.qw = "Was ist die Amtssprache von Mexiko?";
        qa4.an1 = "Portugiesisch";
        qa4.an2 = "Englisch";
        qa4.an3 = "Französisch";
        qa4.an4 = "Spanisch";
        qa4.ar = "d";

        frage qa5;
        qa5.qw = "Unter welchem Namen sangen Wigald Boning und Olli Dittrich Lieder, die die Welt nicht braucht?";
        qa5.an1 = "Die Behaemmerten";
        qa5.an2 = "Die Abgedrehten";
        qa5.an3 = "Die Doofen";
        qa5.an4 = "Die Irren";
        qa5.ar = "c";

        frage qa6;
        qa6.qw = "Was ist ein Rebus?";
        qa6.an1 = "Kreditinstitut";
        qa6.an2 = "Werkzeug";
        qa6.an3 = "Weinstock";
        qa6.an4 = "Bilderraetsel";
        qa6.ar = "d";

        frage qa7;
        qa7.qw = "Wie nennt man von Gletschern transportierten Gesteinsschutt?";
        qa7.an1 = "Moraene";
        qa7.an2 = "Muraene";
        qa7.an3 = "Morelle";
        qa7.an4 = "Murnau";
        qa7.ar = "a";

        frage qa8;
        qa8.qw = "Welches deutsche Fuerstenhaus organisierte bis ins 19. Jahrhundert die kaiserliche Reichspost?";
        qa8.an1 = "Fuerstenberg";
        qa8.an2 = "Schaumburg";
        qa8.an3 = "Hohenlohe";
        qa8.an4 = "Thurn und Taxis";
        qa8.ar = "d";

        frage qa9;
        qa9.qw = "Wobei handelt es sich nicht um ein Insekt?";
        qa9.an1 = "Steckmuecke";
        qa9.an2 = "Wintermücke";
        qa9.an3 = "Grasmuecke";
        qa9.an4 = "Kriebelmuecke";
        qa9.ar = "c";

        frage qa10;
        qa10.qw = "Wie heißt das traditionelle Pferderennen in Siena?";
        qa10.an1 = "Calcio";
        qa10.an2 = "Palio";
        qa10.an3 = "Barolo";
        qa10.an4 = "Boccia";
        qa10.ar = "b";

        frage qa11;
        qa11.qw = "Was ist nach Mahon, dem Hauptort der Insel Menorca, benannt?";
        qa11.an1 = "Marone";
        qa11.an2 = "Mahagoni";
        qa11.an3 = "Marihuana ";
        qa11.an4 = "Mayonese";
        qa11.ar = "d";

        frage qa12;
        qa12.qw = "Welcher deutsche Boxer schlug im Juni 1952 den Ringrichter Max Pippow zu Boden?";
        qa12.an1 = "Peter Mueller";
        qa12.an2 = "Eckhard Dagge";
        qa12.an3 = "Bubi Scholz";
        qa12.an4 = "Max Schmeling";
        qa12.ar = "a";

        frage qa13;
        qa13.qw = "Wo befindet sich der Hauptsitz der UNESCO?";
        qa13.an1 = "Bruessel";
        qa13.an2 = "Paris";
        qa13.an3 = "London";
        qa13.an4 = "Helsinki";
        qa13.ar = "b";

        frage qa14;
        qa14.qw = "Mit wem stand Edmund Hillary 1953 auf dem Gipfel des Mount Everest?";
        qa14.an1 = "Nasreddin Hodscha";
        qa14.an2 = "Nursay Pimsorn";
        qa14.an3 = "Tenzing Norgay";
        qa14.an4 = "Abrindranath Singh";
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
