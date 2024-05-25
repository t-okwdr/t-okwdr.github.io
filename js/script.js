let dif = 0;
var str_dif;
var deg=0;

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
        str_dif='Facile';
    }
    else if (dif==='2'){
        str_dif='Moyen';
    }
    else if (dif==='3'){
        str_dif='Avancé';
    }
    else if (dif==='4'){
        str_dif='Expert';
    }
    else{
        str_dif='ERREUR';
    }
    
}
function wait(seconds){
    seconds*=1000;
    var start = new Date().getTime();
    var end = start;
    while(end < start + ms) {
      end = new Date().getTime();
   }
 }

function flip_card(){
    // alert(document.getElementById('card').className);
    if (document.getElementById('card').className === 'card_flip_180'){
        // document.getElementById("back").style.backfaceVisibility = "hidden";
        deg=(deg+180)%360;
        document.getElementById("card").style.transform = "rotateX(" + deg + "deg)";
        document.getElementById('card').className = 'card_flip_0';
    }
    else if (document.getElementById('card').className === 'card' || document.getElementById('card').className === 'card_flip_0'){
        deg=(deg+180)%360;
        document.getElementById("card").style.transform = "rotateX(" + deg + "deg)";
        document.getElementById('card').className = 'card_flip_180';
        // document.getElementById("back").style.backfaceVisibility = "visible";
    }
}