function maskify(cc) {
    return (Array(cc.length).fill('#').join('')+cc.substr(-4)).substr(-cc.length);
}