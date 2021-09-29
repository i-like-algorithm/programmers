function solution(s) {
    let str = s.toLowerCase().split(' ');
    // console.log(str)
    
    return str.map( string => {
        if (string.charAt(0) >= 'a' && string.charAt(0) <= 'z')
            string = string[0].toUpperCase() + string.slice(1);
        return string;
    }).join(' ')
}