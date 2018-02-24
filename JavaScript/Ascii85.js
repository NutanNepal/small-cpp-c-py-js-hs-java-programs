String.prototype.toAscii85 = function (){
    strlen = this.length;
    string_input = this; //.replace('\0','');
    string_input = (strlen % 4)? string_input + Array(4 - strlen % 4).fill('\0').join(''): string_input;  //pad with null if not length % 4 == 0
    encoded = '';
    for (i = 0; i < strlen; i += 4){
        get32bits = '';
        for (j=0; j < 4; j++){
            //get ascii at (i+j), convert to binary, then change it to 8 bit representation
            get32bits += (i+j < string_input.length)? ("000000000" + string_input.charCodeAt(i+j).toString(2)).substr(-8): '';
        }
        getint = parseInt(get32bits, 2);                //convert 32 bits binary to integer
        getAscii85 = '';
        for (k = 0; k < 5; k++){
            Remainder = getint % 85;                    //convert the integer to base 85
            getint = Math.trunc(getint/85);
            getAscii85 = String.fromCharCode(Remainder + 33) + getAscii85;      //get the asii at remainder+33
        }
        if (strlen > 3){
        encoded += (getAscii85 == '!!!!!')? 'z' : getAscii85;                                                  //decoded
        }
        else{
        encoded += getAscii85;
        }
    }
    returnval = (strlen % 4)? encoded.substr(0, encoded.length - 4 + strlen % 4): encoded;    //return after removing the padded length
    return '<~' + returnval + '~>';
};
    
String.prototype.fromAscii85 = function (){
    string_input = this.replace(/\s/g,'').replace(/z/g,'!!!!!').slice(2, -2);
    strlen = string_input.length;
    string_input = (strlen % 5)? string_input+ Array(5 - strlen % 5).fill('u').join(''): string_input;  //pad with u if not length % 5 == 0
    decoded = '';
    for (i = 0; i < strlen; i += 5){
        getint= 0;
        for (j=0; j < 5; j++){
            getint += Math.pow(85,4-j) * (string_input.charCodeAt(i+j) - 33);
        }
        get32bits = ("00000000000000000000000000000000" + getint.toString(2)).substr(-32);
        getchars = ''
        for (k= 0; k < 4; k++){
            getchars += String.fromCharCode(parseInt(get32bits.slice(0, 8), 2));
            get32bits = get32bits.slice(8);
        }
        decoded += getchars;
    }
    returnval = (strlen % 5)? decoded.substr(0, decoded.length - 5 + strlen % 5): decoded;
    return returnval;
};

//console.log("<~ARTY*~>".fromAscii85() == 'easy');
//console.log('\u0000\u0000\u0000\u0000zero-prefixed'.toAscii85() == '<~zH=_,8/T>`AAncL$A,~>');
console.log('<~!!!~>'.fromAscii85() == '\u0000\u0000');
console.log('<~zH=_,8/T>`AAncL$A,~>'.fromAscii85());
console.log('<~;f?Ma+92BAz!!$qJA0:jPzz!!!"FATD^#F!(G_zz!,,qaAK_~>'.fromAscii85());
//console.log('<~GA(]4A\nTMg!@q\n?d)ATM\nr91&~>'.fromAscii85() == 'whitespace test 2');