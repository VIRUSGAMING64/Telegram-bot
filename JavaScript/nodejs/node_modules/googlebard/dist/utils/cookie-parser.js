function CookieParser(setCookies, cookies) {
    setCookies.forEach((cookie) => {
        const cookieParts = cookie.split(";")[0].split("=");
        const cookieName = cookieParts[0];
        const cookieValue = cookieParts[1];
        const existingCookieIndex = cookies.FirstOrDefault((c) => c.name === cookieName);
        if (existingCookieIndex) {
            existingCookieIndex.value = cookieValue;
        }
        else {
            cookies.Add({
                name: cookieName,
                value: cookieValue,
            });
        }
    });
}
export default CookieParser;
//# sourceMappingURL=cookie-parser.js.map