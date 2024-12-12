var appendTools = (name, icon, className, docUrl) => {
    var skillsDisplay = document.querySelector(className);
    var skillBox = `
        <!-- ${name} -->
        <div class="skill-box">
            <div class="skill-logo" data-doc="${docUrl}">
                <i class="${icon}"></i>
            </div>
            <div class="skill-name">
                <span>${name}</span>
            </div>
        </div>
    `;

    skillsDisplay.innerHTML += skillBox;
};

var skills = {
    "C": { icon: "devicon-c-plain-wordmark colored", doc: "https://en.wikipedia.org/wiki/C_(programming_language)" },
    "Java": { icon: "devicon-java-plain colored", doc: "https://docs.oracle.com/en/java/" },
    "Python": { icon: "devicon-python-plain", doc: "https://www.python.org/doc/" },
    "HTML": { icon: "devicon-html5-plain colored", doc: "https://developer.mozilla.org/en-US/docs/Web/HTML" },
    "CSS": { icon: "devicon-css3-plain colored", doc: "https://developer.mozilla.org/en-US/docs/Web/CSS" },
    "Javascript": { icon: "devicon-javascript-plain colored", doc: "https://developer.mozilla.org/en-US/docs/Web/JavaScript" }
};

for (const lang in skills) {
    var { icon, doc } = skills[lang];
    appendTools(lang, icon, '.skills-display', doc);
}

var frameworkAndLibs = {
    "Node.js": { icon: "devicon-nodejs-plain colored", doc: "https://nodejs.org/" },
    "Express.js": { icon: "devicon-express-original", doc: "https://expressjs.com/" },
    "React.js": { icon: "devicon-react-original colored", doc: "https://reactjs.org/" },
    "Next.js": { icon: "devicon-nextjs-original", doc: "https://nextjs.org/" },
    "Tailwind": { icon: "devicon-tailwindcss-plain colored", doc: "https://tailwindcss.com/" }
};

for (const skill in frameworkAndLibs) {
    var { icon, doc } = frameworkAndLibs[skill];
    appendTools(skill, icon, '.framework-libs-display', doc);
}

var dbms = {
    "MySQL": { icon: "devicon-mysql-plain colored", doc: "https://dev.mysql.com/doc/" },
    "MongoDB": { icon: "devicon-mongodb-plain colored", doc: "https://www.mongodb.com/docs/" },
    "PostgreSQL": { icon: "devicon-postgresql-plain colored", doc: "https://www.postgresql.org/docs/" }
};

for (const db in dbms) {
    var { icon, doc } = dbms[db];
    appendTools(db, icon, '.dbms-display', doc);
}

var devTools = {
    "Git": { icon: "devicon-git-plain", doc: "https://git-scm.com/doc" },
    "GitHub": { icon: "devicon-github-original", doc: "https://docs.github.com/" }
};

for (const tool in devTools) {
    var { icon, doc } = devTools[tool];
    appendTools(tool, icon, '.dev-tools', doc);
}

document.addEventListener("click", (event) => {
    const skillLogo = event.target.closest(".skill-logo");
    if (skillLogo) {
        const docUrl = skillLogo.getAttribute("data-doc");
        if (docUrl) {
            window.open(docUrl, "_blank");
        }
    }
});
