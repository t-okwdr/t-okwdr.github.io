let dif = 0;
var str_dif;
var deg=0;
let flipped=false;
var question_dif = [];

var medium = [];
//Present
medium[0]={question: "Conjugue la phrase au présent:  Il ___ (tomber) d’une montagne et il ___ (mourir).",
answer_count: 2, answer1: "tombe", answer2: "meurt"};
medium[1]={question: "Conjugue la phrase au présent: Je ___ (vouloir) ___ (devenir) un médecin.",
answer_count: 1, answer1: "veux devenir"};
medium[2]={question: "Conjugue la phrase au présent: Tu ___ (revenir) à la maison.",
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
medium[7]={question: "Comment on conjugue le verbe “recevoir” au passe compose avec “Vous”?",
answer_count: 1, answer1: "vous avez recu"};

//Futur Proche
medium[8]={question: "Utilise l’inversion (question) et récrire la phrase au futur proche:\n“Il reste après le marathon”",
answer_count: 1, answer1: "va t il rester apres le marathon"};
medium[9]={question: "Utilise l’inversion (question) et récrire la phrase au futur proche:\n“Elle prend un sandwich”",
answer_count: 1, answer1: "va t elle prendre un sandwich"};
medium[10]={question: "Utilise l’inversion (question) et récrire la phrase au futur proche: “Vous posez une question au prof”",
answer_count: 1, answer1: "allez vous poser une question au prof"};

//Verbes Pronominaux
medium[11]={question: "Conjuguer le verbe pronominal “se laver” au présent avec “Vous”.",
answer_count: 1, answer1: "vous vous lavez"};
medium[12]={question: "Transformez la phrase suivante au passe compose:\n“Elle se maquille”",
answer_count: 1, answer1: "elle sest maquillee"};
medium[13]={question: "Conjuguez le verbe pronominal “se lever” au futur proche avec “Tu”.",
answer_count: 1, answer1: "tu vas te lever"};
// medium[14]={question: "Conjuguez le verbe pronominal “se réveiller” au présent pour tous les pronoms.",
// answer_count: 1, answer1: "nous sommes morts"};

//Futur Simple
medium[15]={question: "Conjuguez le verbe “aller” au futur simple pour “nous”.",
answer_count: 1, answer1: "Nous irons"};
medium[16]={question: "Réécrivez la phrase suivante au futur simple: “Je fais mes devoirs”.",
answer_count: 1, answer1: "je ferai mes devoirs"};
medium[17]={question: "Conjuguez le verbe “prendre” au futur simple pour “Elles”.",
answer_count: 1, answer1: "elles prendront"};
medium[18]={question: "Transformez la phrase suivante au futur simple: “Nous finissons notre projet”.",
answer_count: 1, answer1: "nous finirons notre projet"};


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
        userItem.style.visibility = 'hidden';
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