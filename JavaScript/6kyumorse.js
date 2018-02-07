console.log(decoder('.... . -.--   .--- ..- -.. .'))

function decoder(morsecodes){
    duplicate = morsecodes.trim();
    var words = [];
    do{
        end = 0;
        var nextthreespaces = morsecodes.indexOf("   ");
        if (nextthreespaces !== -1){
            var word = duplicate.slice(0, nextthreespaces);
            end = nextthreespaces +3;
            duplicate = duplicate.replace(duplicate.slice(0, end), "")
            words.push(word)
        }
        else{
            words.push(duplicate);
        }
    }while(nextthreespaces !== -1);

    for (i = 0; i < words.length; i++){
        nextword = words[i];
        output = '';
        do{
            end = 0;
            var nextwhitespace = nextword.indexOf(" ");
            if (nextwhitespace !== -1){
                var letter = nextword.slice(0, nextwhitespace);
                end = nextwhitespace + 1;
                nextword = nextword.replace(nextword.slice(0, end), "")
                output += MORSE_CODE[letter];
            }
            else{
                output += MORSE_CODE[letter] + ' ';
            }
        }while(nextthreespaces !== -1);
    }
    output.trim();
    return output
}

MORSE_CODE= {
    ".-": "A",
    "-...": "B",
    "-.-.": "C",
    "-..": "D",
    ".": "E",
    "..-.": "F",
    "--.": "G",
    "....": "H",
    "..": "I",
    ".---": "J",
    "-.-": "K",
    ".-..": "L",
    "--": "M",
    "-.": "N",
    "---": "O",
    ".--.": "P",
    "--.-": "Q",
    ".-.": "R",
    "...": "S",
    "-": "T",
    "..-": "U",
    "...-": "V",
    ".--": "W",
    "-..-": "X",
    "-.--": "Y",
    "--..": "Z",
    "-----": "0",
    ".----": "1",
    "..---": "2",
    "...--": "3",
    "....-": "4",
    ".....": "5",
    "-....": "6",
    "--...": "7",
    "---..": "8",
    "----.": "9",
    " ": "/"
};