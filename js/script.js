let dif = 0;
var str_dif;
var deg=0;
let flipped=false;
var question_dif = [];

var easy = [];
//Present
easy[0]={question: "Je _____ (manger) un sandwich au jambon.",
answer_count: 2, answer1: "mange"};
easy[1]={question: "Conjuguez le verbe “être” au présent pour tous les pronoms. (Utilisez il/ils)",
answer_count: 6, answer1: "je suis", answer2: "tu es", answer3: "il est",
answer4: "nous sommes", answer5: "vous etes", answer6: "ils sont"};
easy[2]={question: " Ils _____ (parler) de leur enseignant.",
answer_count: 1, answer1: "parlent"};
easy[3]={question: "Conjuguez le verbe “finir” au présent pour tous les pronoms. (Utilisez il/ils)",
answer_count: 6, answer1: "je finis", answer2: "tu finis", answer3: "il finit",
answer4: "nous finissons", answer5: "vous finissez", answer6: "ils finissent"};
easy[4]={question: "Conjuguez le verbe “prendre” au présent pour tous les pronoms. (Utilisez il/ils)",
answer_count: 6, answer1: "je prends", answer2: "tu prends", answer3: "il prend",
answer4: "nous prenons", answer5: "vous prenez", answer6: "ils prennent"};
easy[5]={question: "Conjuguez le verbe “aller” au présent pour tous les pronoms. (Utilisez il/ils)",
answer_count: 6, answer1: "je vais", answer2: "tu vas", answer3: "il va",
answer4: "nous allons", answer5: "vous allez", answer6: "ils vont"};
easy[6]={question: "Vous ______ (apprendre) l’anglais.",
answer_count: 1, answer1: "apprenez"};

//Passe Compose
easy[7]={question: "Comment on conjugué le verbe “avoir” au passé composé avec “Je”?",
answer_count: 1, answer1: "jai eu"};
easy[8]={question: "Comment on conjugué le verbe “être” au passé composé avec “Vous”?",
answer_count: 1, answer1: "vous avez ete"};
easy[9]={question: "Comment on conjugué le verbe “prendre” au passé composé avec “Nous”?",
answer_count: 1, answer1: "nous avons pris"};
easy[10]={question: "Comment on conjugué le verbe “finir” au passé composé avec “Ils”?",
answer_count: 1, answer1: "ils ont fini"};
easy[11]={question: "Comment on conjugué le verbe “descendre” au passé composé avec “Elles”?",
answer_count: 1, answer1: "elles sont descendues"};

//Futur Proche
easy[12]={question: "Récrivez la phrase: “Tu manges un sandwich” au futur proche.",
answer_count: 1, answer1: "tu vas manger un sandwich"};
easy[13]={question: "Quelle est la verbe auxiliaire pour le futur proche.",
answer_count: 1, answer1: "aller"};
easy[14]={question: "Conjuguez “ils parlent” au futur proche.",
answer_count: 1, answer1: "ils vont parler"};
easy[15]={question: "Récrivez la phrase: “Vous faites une promenade” au futur proche.",
answer_count: 1, answer1: "vous allez faire une promenade"};
easy[16]={question: "Récrivez la phrase: “J'étudie pour l’examen” au futur proche.",
answer_count: 1, answer1: "je vais etudier pour lexamen"};
easy[17]={question: "Conjuguez “Nous descendons” au futur proche.",
answer_count: 1, answer1: "nous allons descendre"};
easy[18]={question: "Conjuguez “Elle sort” au futur proche.",
answer_count: 1, answer1: "elle va sortir"};

//Imparfait
easy[19]={question: "Conjuguez à l’imparfait: “Ce matin, je ____ (manger) mon petit-déjeuner”.",
answer_count: 1, answer1: "mangeais"};
easy[20]={question: "Comment on conjugue le verbe “être” à l'imparfait avec “Ils”?",
answer_count: 1, answer1: "ils etaient"};
easy[21]={question: "Comment on conjugue le verbe “venir à l'imparfait avec “Vous”?",
answer_count: 1, answer1: "vous veniez"};
easy[22]={question: "Récrivez la phrase à l'imparfait: “Il a dormi après l'école”.",
answer_count: 1, answer1: "il dormait apres lecole"};
easy[23]={question: "Écrivez tous les terminaisons pour l'imparfait.",
answer_count: 6, answer1: "ais", answer2: "ais", answer3: "ait", answer4: "ions", answer5: "iez", answer6: "aient"};

//Vocabulaire
easy[24]={question: "Conjuguer la phrase avec l’expression idiomatique: “Aujourd’hui, J’ ______ (avoir 16 ans)”.",
answer_count: 1, answer1: "ai 16 ans"};
easy[25]={question: "Quelle est l'auxiliaire pour l’expression idiomatique: “____ dans le doute”?",
answer_count: 1, answer1: "etre"};
easy[26]={question: "Quel mot veut dire “volunteer” et commence avec un ‘b’?",
answer_count: 1, answer1: "benevole"};

//Connaissances Variees (unfinished)
easy[27]={question: "Conjuguez le verbe “prendre” au futur simple pour “Elles”.",
answer_count: 1, answer1: "elles prendront"};
easy[28]={question: "Transformez la phrase suivante au futur simple: “Nous finissons notre projet”.",
answer_count: 1, answer1: "nous finirons notre projet"};
easy[29]={question: "Transformez la phrase suivante au futur simple: “Nous finissons notre projet”.",
answer_count: 1, answer1: "nous finirons notre projet"};


var medium = [];
//Present
medium[0]={question: "Conjuguez la phrase au présent:  Il ___ (tomber) d’une montagne et il ___ (mourir).",
answer_count: 2, answer1: "tombe", answer2: "meurt"};
medium[1]={question: "Conjuguez la phrase au présent: Je ___ (vouloir) ___ (devenir) un médecin.",
answer_count: 1, answer1: "veux devenir"};
medium[2]={question: "Conjuguez la phrase au présent: Tu ___ (revenir) à la maison.",
answer_count: 1, answer1: "reviens"};

//Passe Compose
medium[3]={question: "Comment on conjugue le verbe “vouloir” au passé composé avec “Je”?",
answer_count: 1, answer1: "jai voulu"};
medium[4]={question: "Comment on conjugue le verbe “pouvoir” au passé composé avec “Tu”?",
answer_count: 1, answer1: "tu as pu"};
medium[5]={question: "Comment on conjugue le verbe “vivre” au passé composé avec “Il”?",
answer_count: 1, answer1: "il a vecu"};
medium[6]={question: "Comment on conjugue le verbe “mourir” au passé composé avec “Nous” (masc.)?",
answer_count: 1, answer1: "nous sommes morts"};
medium[7]={question: "Comment on conjugue le verbe “recevoir” au passé composé avec “Vous”?",
answer_count: 1, answer1: "vous avez recu"};

//Futur Proche
medium[8]={question: "Utilise l’inversion (question) et récrivez la phrase au futur proche:\n“Il reste après le marathon”",
answer_count: 1, answer1: "va t il rester apres le marathon"};
medium[9]={question: "Utilise l’inversion (question) et récrivez la phrase au futur proche:\n“Elle prend un sandwich”",
answer_count: 1, answer1: "va t elle prendre un sandwich"};
medium[10]={question: "Utilise l’inversion (question) et récrivez la phrase au futur proche: “Vous posez une question au prof”",
answer_count: 1, answer1: "allez vous poser une question au prof"};

//Verbes Pronominaux
medium[11]={question: "Conjuguez le verbe pronominal “se laver” au présent avec “Vous”.",
answer_count: 1, answer1: "vous vous lavez"};
medium[12]={question: "Transformez la phrase suivante au passé composé:\n“Elle se maquille”",
answer_count: 1, answer1: "elle sest maquillee"};
medium[13]={question: "Conjuguez le verbe pronominal “se lever” au futur proche avec “Tu”.",
answer_count: 1, answer1: "tu vas te lever"};
medium[14]={question: "Conjuguez le verbe pronominal “se réveiller” au présent pour tous les pronoms. (Utilisez il/ils)",
answer_count: 6, answer1: "je me reveille", answer2: "tu te reveilles", answer3: "il se reveille",
answer4: "nous nous reveillons", answer5: "vous vous reveillez", answer6: "ils se reveillent"};

//Futur Simple
medium[15]={question: "Conjuguez le verbe “aller” au futur simple pour “nous”.",
answer_count: 1, answer1: "nous irons"};
medium[16]={question: "Réécrivez la phrase suivante au futur simple:\n“Je fais mes devoirs”.",
answer_count: 1, answer1: "je ferai mes devoirs"};
medium[17]={question: "Conjuguez le verbe “prendre” au futur simple pour “Elles”.",
answer_count: 1, answer1: "elles prendront"};
medium[18]={question: "Transformez la phrase suivante au futur simple:\n“Nous finissons notre projet”.",
answer_count: 1, answer1: "nous finirons notre projet"};

//Imparfait
medium[19]={question: "Comment on conjugue le verbe “rire” à l'imparfait avec “Nous”?",
answer_count: 1, answer1: "nous riions"};
medium[20]={question: "Conjuguez à l’imparfait.\n“Ma mère ______ (se peigner) les cheveux”.",
answer_count: 1, answer1: "se peignait"};

//Conditionnel Present
medium[21]={question: "Conjuguez le verbe “falloir” au conditionnel pour tous les pronoms. (Utilisez il/ils)",
answer_count: 6, answer1: "je faudrais", answer2: "tu faudrais", answer3: "il faudrait",
answer4: "nous faudrions", answer5: "vous faudriez", answer6: "ils faudraient"};
medium[22]={question: "Conjuguez le verbe “jeter” au conditionnel pour “Il”.",
answer_count: 1, answer1: "Il jetterait"};
medium[23]={question: "Conjuguez au conditionnel:\n“Si j’avais du temps, je _______ (démarrer) une entreprise”.",
answer_count: 1, answer1: "demarrerais"};

//Vocabulaire
medium[24]={question: "Quelle est l’expression qui veut dire “to take place?",
answer_count: 1, answer1: "avoir lieu"};
medium[25]={question: "Quelle est l’expression qui veut dire “to keep in touch”?",
answer_count: 1, answer1: "rester en contact"};
medium[26]={question: "Quel nom veut dire “Une personne qui voyage beaucoup”?",
answer_count: 1, answer1: "globe trotteur"};

//Connaissances Variees (unfinished)
medium[27]={question: "Conjuguez le verbe “prendre” au futur simple pour “Elles”.",
answer_count: 1, answer1: "elles prendront"};
medium[28]={question: "Transformez la phrase suivante au futur simple: “Nous finissons notre projet”.",
answer_count: 1, answer1: "nous finirons notre projet"};
medium[29]={question: "Transformez la phrase suivante au futur simple: “Nous finissons notre projet”.",
answer_count: 1, answer1: "nous finirons notre projet"};



var hard = [];
//Passe Compose
hard[0]={question: "Conjuguez la phrase: Elle se les (les dents) est ____ (se brosser).",
answer_count: 1, answer1: "brossees"};
hard[1]={question: "Nous nous la (la mémoire) sommes ____ (se souvenir).",
answer_count: 1, answer1: "souvienne"};
hard[2]={question: "Trouvez l’objet direct et récrivez la phrase au passé composé:\n“Nous découvrons le centre-ville”.",
answer_count: 1, answer1: "nous lavons decouvert"};
hard[3]={question: "Trouvez l’objet direct et récrivez la phrase au passé composé:\n“J'ouvre toutes les fenêtres”.",
answer_count: 1, answer1: "je les ai ouvertes"};

//Plus-Que-Parfait
hard[4]={question: "Conjuguez au plus-que-parfait:\n“Ils ________ (assassiner) leurs parents”.",
answer_count: 1, answer1: "avaient assassine"};
hard[5]={question: "Conjuguez au plus-que-parfait:\n“Sa nouvelle entreprise ________ (ouvrir) avant la pandémie”.",
answer_count: 1, answer1: "avait ouvert"};
hard[6]={question: "Conjuguez au plus-que-parfait:\n“Je ________ (ne plus se relaxer) après le travail”. (masc.)",
answer_count: 1, answer1: "ne metais plus relaxe"};
hard[7]={question: "Conjuguez au plus-que-parfait:\n“Tu ________ (arriver) plus tôt que moi”. (masc.)",
answer_count: 1, answer1: "etais arrive"};

//Imparfait
hard[8]={question: "Comment on conjugue le verbe “peindre” à l'imparfait avec “Je”.",
answer_count: 1, answer1: "je peignais"};
hard[9]={question: "Trouvez l'objet direct et indirect et récrivez la phrase à l'imparfait:\n“Nous donnons le livre à Paul”.",
answer_count: 1, answer1: "nous le lui donnions"};
hard[10]={question: "Comment on conjugue le verbe “croître” à l'imparfait avec “Elles”?",
answer_count: 1, answer1: "elles croissaient"};

//Imparfait
hard[11]={question: "Écrivez les racines des trois semi-auxiliaires au conditionnel. (dans l’ordre: “Vouloir, Pouvoir, Devoir)”",
answer_count: 3, answer1: "voudr", answer2: "pourr", answer3: "devr"};
hard[12]={question: "Trouvez les pronoms compléments et récrivez la phrase au conditionnel: “Nous déposer son amie au cinéma”.",
answer_count: 1, answer1: "nous l'y deposerions"};
hard[13]={question: "Conjuguez les verbes “avoir, être, faire, aller” au conditionnel pour “Tu” (dans cet ordre).",
answer_count: 4, answer1: "tu aurais", answer2: "tu serais", answer3: "tu ferais", answer4: "tu irais"};

//Gerondif/Adjectif Verbal
hard[14]={question: "Complétez la phrase avec le gérondif:\n“Il mange un sandwich _______ (cuisiner)”.",
answer_count: 1, answer1: "en cuisinant"};
hard[15]={question: "Complétez la phrase avec le gérondif:\n“Il y a un chat _____ (courir) d’un chien”.",
answer_count: 1, answer1: "courant"};
hard[16]={question: "Complétez la phrase avec le gérondif:\n“Vous devenez un milliardaire ______ (travailler) forte”.",
answer_count: 1, answer1: "en travaillant"};

//Vocabulaire
hard[20]={question: "Quel type de connecteur est “en d'autres termes” exprime?",
answer_count: 1, answer1: "Reformulation"};
hard[21]={question: "Quels sont les mots pour “Teacher (m.), High School, University” en français?",
answer_count: 3, answer1: "enseignant", answer2: "lycee", answer3: "universite"};
hard[22]={question: "Quelle phrase veut dire “see where the wind takes you”?",
answer_count: 1, answer1: "partir a laventure"};

//Verbes Pronominaux
hard[20]={question: "Conjuguez le verbe pronominal “s'amuser” à l'imparfait pour “Nous”.?",
answer_count: 1, answer1: "nous nous amusions"};
hard[21]={question: "Comment on conjugue le verbe “vivre” au passé composé avec “Il”?",
answer_count: 1, answer1: "quil se promene."};
hard[22]={question: "Conjuguez le verbe pronominal “se souvenir” au passé composé pour toutes les personnes. (Supposez masc.)",
answer_count: 6, answer1: "je me suis souvenu", answer2: "tu tes souvenu", answer3: "il sest souvenu",
answer4: "nous nous sommes souvenus", answer5: "vous vous etes souvenus", answer6: "ils se sont souvenus"};

//Futur Simple
hard[23]={question: "Conjuguez le verbe “envoyer” au futur simple pour toutes les personnes. (Utilisez il/ils)",
answer_count: 6, answer1: "jenverrai", answer2: "tu enverras", answer3: "il enverra",
answer4: "nous enverrons", answer5: "vous enverrez", answer6: "ils enverront"};
hard[24]={question: "Recrivez la phrase suivante au futur simple:\n“Nous finissons nos devoirs”.",
answer_count: 1, answer1: "nous finirons nos devoirs"};
hard[25]={question: "Conjuguez le verbe pronominal “se lever” au futur simple pour toutes les personnes. (Utilisez il/ils)",
answer_count: 6, answer1: "je me leverai", answer2: "tu te leveras", answer3: "il se levera",
answer4: "nous nous leverons", answer5: "vous vous leverez", answer6: "ils se leveront"};
hard[26]={question: "Recrivez la phrase suivante au futur simple:\n“Les enfants sont heureux”.",
answer_count: 1, answer1: "les enfants seront heureux"};

//Connaissances Variees (unfinished)
hard[27]={question: "Conjuguez le verbe “prendre” au futur simple pour “Elles”.",
answer_count: 1, answer1: "elles prendront"};
hard[28]={question: "Transformez la phrase suivante au futur simple: “Nous finissons notre projet”.",
answer_count: 1, answer1: "nous finirons notre projet"};
hard[29]={question: "Transformez la phrase suivante au futur simple: “Nous finissons notre projet”.",
answer_count: 1, answer1: "nous finirons notre projet"};


var expert = [];
//Conditionnel Present
expert[0]={question: "Utilisez l’inversion, trouvez le pronom complément et récrivez la phrase au conditionnel: “Est-ce que vous partir chez John maintenant”.",
answer_count: 1, answer1: "partiriez vous y maintenant"};
expert[1]={question: "Trouvez les pronoms compléments et récrivez la phrase au conditionnel: “J’envoie un email à mon patron à 3h”.",
answer_count: 1, answer1: "souvienne"};

//Gerondif/Adjectif Verbal
expert[2]={question: "Trouvez l’objet direct et récrivez la phrase au passé composé:\n“Nous voulons découvrir le centre-ville”.",
answer_count: 1, answer1: "nous lavons decouvert"};
expert[3]={question: "Trouvez l’objet direct et récrivez la phrase au passé composé:\n“Je veux ouvrir toutes les fenêtres”.",
answer_count: 1, answer1: "je le lui y enverrais"};

//Verbes Pronominaux (Ask Mo about 5)
expert[4]={question: "Conjuguez le verbe pronominal “se rappeler” au passé antérieur pour “nous”. (masc.)",
answer_count: 1, answer1: "nous nous fumes rappeles"};
expert[5]={question: "Conjuguez le verbe pronominal “se rappeler” au passé antérieur pour “nous”. (masc.)",
answer_count: 1, answer1: "nous nous fumes rappeles"};

//Imparfait
expert[6]={question: "Conjuguez cette phrase:\n“Nous ______ (devoir) travailler très forte, si nous ______ (vouloir) réussir”.",
answer_count: 2, answer1: "devrons", answer2: "voulons"};
expert[7]={question: "Conjuguez le verbe “devoir” au futur simple pour toutes les personnes et conjuguez la phrase: “Demain, Je _____ (pouvoir) terminer mon projet”.",
answer_count: 7, answer1: "je devrai", answer2: "tu devras", answer3: "il devra",
answer4: "nous devrons", answer5: "vous devrez", answer6: "ils devront", answer7: "pourrai"};

//Connaissances Variees (unfinished)
expert[8]={question: "Comment on conjugue le verbe “peindre” à l'imparfait avec “Je”.",
answer_count: 1, answer1: "je peignais"};
expert[9]={question: "Trouvez l'objet direct et indirect et récrivez la phrase à l'imparfait:\n“Nous donnons le livre à Paul”.",
answer_count: 1, answer1: "nous le lui donnions"};



const removeAccents = str =>
  str.normalize('NFD').replace(/[\u0300-\u036f]/g, '');

function compress(answer){
    answer = answer.toLowerCase();
    answer = removeAccents(answer);
    answer = answer.replace(/[.,\/#!$%\^&\*;:{}=\_`~()\'\"]/g,"");
    answer = answer.replace(/[-]/g," ");
    // alert(answer);
    return answer;
}

function check(){
    var ans = [];
    var correct=0;
    var ans_count=question_dif[question_num].answer_count;

    for (var i=0;i<ans_count;i++){
        ans[i]=document.getElementById("ans-"+(i+1)).value;
        ans[i]=compress(ans[i]);
    }
    for (var i=0;i<ans_count;i++){
        // alert(ans[i]);
        if (ans[i]==question_dif[question_num]["answer"+(i+1)]){
            correct++;
        }
    }
    const boxes = document.querySelectorAll(".answer");
    boxes.forEach((userItem) => {
        userItem.remove();
        // userItem.style.visibility = 'hidden';
    });
    if (correct==ans_count){
        alert("All answers correct!");
    }
    else{
        alert("You suck loser!")
    }
}


function cloneElement() {
    const elementToClone = document.querySelector(".answer");
    const clonedElement = elementToClone.cloneNode(true);
    clonedElement.id = "div-"+(i+1);
    container.appendChild(clonedElement);
    var cloneChild = document.getElementById(clonedElement.id).firstElementChild;
    cloneChild.id = "ans-"+(i+1);
    cloneChild.style.width = ((question_dif[question_num]["answer"+(i+1)].length*16)+50)+"px";
    // document.getElementById(clonedElement.id).childNodes = "ans-"+(i+1);
    // console.log(document.getElementById(clonedElement.id).childNodes[0]);
}

function rand(min,max) {
    const minCeiled = Math.ceil(min);
    const maxFloored = Math.floor(max);
    return Math.floor(Math.random() * (maxFloored - minCeiled + 1) + minCeiled);
    // The maximum is inclusive and the minimum is inclusive
  }
function get_card_info(value){
    const cards = [];
    //English
    // cards[1]="Start a piece, or move forwards 1";
    // cards[2]="Start a piece, or move forwards 2, AND draw again";
    // cards[3]="Move forwards 3";
    // cards[4]="Move backwards 4";
    // cards[5]="Move forwards 5";
    // cards[7]="Move forwards 7, or split the move between two pieces";
    // cards[8]="Move forwards 8";
    // cards[10]="Move forwards 10, or move backwards 1";
    // cards[11]="Move forwards 11, or switch your piece with an opponent\’s";
    // cards[12]="Move forwards 12";
    // cards[13]="Take a piece from start, place it on any opponent\’s piece, and knock that piece back to start";

    //French
    cards[1]="Démarrez une pièce, ou bougez 1 vers l'avant";
    cards[2]="Démarrez une pièce, ou bougez 2 vers l'avant, ET tirez encore";
    cards[3]="Bougez 3 vers l'avant";
    cards[4]="Bougez 4 vers l'arrière";
    cards[5]="Bougez 5 vers l'avant";
    cards[7]="Bougez 7 vers l'avant, ou divisez le tour entre deux pièces";
    cards[8]="Bougez 8 vers l'avant";
    cards[10]="Bougez 10 vers l'avant, ou bougez 1 vers l'arrière";
    cards[11]="Bougez 11 vers l'avant, ou changez votre pièce avec une d'un adversaire";
    cards[12]="Bougez 12 vers l'avant";
    cards[13]="Prenez une pièce du Départ, mettez-le sur une d'un adversaire, and heurtez cette pièce au Départ";
    if (value=="DÉSOLÉE!"){
        return cards[13];
    }
    return cards[Number(value)];
}

function getLines(ctx, text, maxWidth) {
    var line_break = text.split("\n");
    var words = line_break[0].split(" ");
    var lines = [];
    var currentLine = words[0];

    for (var i = 1; i < words.length; i++) {
        var word = words[i];
        var width = ctx.measureText(currentLine + " " + word).width;
        // alert(width);
        if (width < maxWidth) {
            currentLine += " " + word;
        } else {
            lines.push(currentLine);
            currentLine = word;
        }
    }
    lines.push(currentLine);
    if (line_break[1]){
        lines.push(line_break[1]);
    }
    
    return lines;
}

function generate_card(){
    var num;
    var card;
    var str_card;
    num=rand(0,99);
    if (dif==='1'){
        if (num<78){
            card=rand(3,5);
        }
        else if (num<98){
            do {
                card=rand(1,11);
            } while (card==3 || card==4 || card==5 || card==11);
        }
        else{
            card=11;
        }
    }
    else if (dif==='2'){
        if (num<60){
            do {
                card=rand(1,7);
            } while (card==2);
        }
        else if (num<95){
            do {
                card=rand(2,11);
            } while ((card!=2 && card<8) || card==11);
        }
        else{
            card=11;
        } 
    }
    else if (dif==='3'){
        if (num<40){
            do {
                card=rand(1,11);
            } while (!(card==1 || card==2 || card==6 || card==9 || card==11));
        }
        else{
            do {
                card=rand(1,11);
            } while (card==1 || card==2 || card==6 || card==9 || card==11);
        }
    }
    else if (dif==='4'){
        do {
            card=rand(1,11);
        } while (!(card==1 || card==2 || card==6 || card==9 || card==11));
    }
    if (card==6){
        card=7;
    }
    else if(card==7){
        card=8;
    }
    else if(card==8){
        card=10;
    }
    else if(card==9){
        card=11;
    }
    else if(card==10){
        card=12;
    }
    else if(card==11){
        card=13;
    }
    if (card<13){
        str_card=card.toString();
    }
    else{
        str_card="DÉSOLÉE!";
    }
    // alert(str_card);
    return str_card;
}
function fra_manual() {
    const changeText = document.querySelector("#rule-title");
    const changeTitle = document.querySelector("#subtitle");
    document.getElementById("logo").src="images/Sorry Title.png";
    document.getElementById("eng").style.display = 'none';
    document.getElementById("fra").style.display = 'flex';
    changeText.textContent = "Retournez au Menu Principal";
    changeTitle.textContent = "Le Jeu de Vengeance Gratifiant!";
}
function eng_manual() {
    const changeText = document.querySelector("#rule-title");
    const changeTitle = document.querySelector("#subtitle");
    document.getElementById("logo").src="images/Sorry Logo.png";
    document.getElementById("fra").style.display = 'none';
    document.getElementById("eng").style.display = 'flex';
    changeText.textContent = "Back to Main Menu";
    changeTitle.textContent = "The Game of Sweet Revenge!";
}

function set_dif(difficulty){
    dif=difficulty;
}

function set_str_dif(){
    if (dif==='1'){
        str_dif='FACILE';
    }
    else if (dif==='2'){
        str_dif='MOYEN';
    }
    else if (dif==='3'){
        str_dif='AVANCÉ';
    }
    else if (dif==='4'){
        str_dif='EXPERT';
    }
    else{
        str_dif='ERREUR';
    }
    
}
function wait(seconds){
    ms = seconds * 1000;
    var start = new Date().getTime();
    var end = start;
    while(end < start + ms) {
      end = new Date().getTime();
   }
 }



function flipcard(){
    if (flipped==false){
        const card = document.querySelector("flip-card");
        card.setFlipToFrontAnimation(
            [ {
                transform: "translateZ(calc(-1 * var(--_depth))) rotateX(180deg)",
            }, {
                transform: "translateZ(var(--_height)) rotateX(270deg)",
            }, {
                transform: "translateZ(0em) rotateX(360deg)",
            } ],
            {
                easing: "ease-in-out",
            },
        )
        
        card.setFlipToBackAnimation(
            [ {
                transform: "translateZ(0em) rotateX(0deg)",
            }, {
                transform: "translateZ(var(--_height)) rotateX(90deg)",
            }, {
                transform: "translateZ(calc(-1 * var(--_depth))) rotateX(180deg)",
            } ],
            {
                easing: "ease-in-out",
            },
        )
        card.flip();
        flipped=true;
        while (card=='flipped'){

        }
        card.addEventListener('flipped', e => {
            // alert(e.detail.facedown);
            document.getElementById("data").style.visibility = 'visible';
            const boxes = document.querySelectorAll(".answer");
            boxes.forEach((userItem) => {
                userItem.style.visibility = 'visible';
              });
        })
        // alert(card);
        document.getElementById("card-back").style.visibility = 'visible';
    }
}