## <div style="color:#f59800" align="center">---| NeoGauge - System monitor widget for Windows |---</div>

## About this project:
 This is a system monitor skin for RainMeter that displays various system information on your desktop.
It is highly customizable and can be configured to display any information you want,
from hardware temps, CPU usage and clock speed to network download/upload speeds and everything in between.

It also has a built-in configuration tool that allows you to easily customize the skin without having to edit any files manually.

This skin is inspired and based on [flyinghyrax](https://www.deviantart.com/flyinghyrax)

### The RainMeter story:

Rainmeter is a free, open-source application for Windows PCs. It is a platform that enables skins to run on the desktop.

It allows users to create and display user-generated customizable desktop widgets
or applets called "skins" that display information.

Rainmeter will run on any Windows PC running Windows 7 or later.
It was first designed to display weather information but now can also be used to display other information such as RSS feeds, calendar, e-mail, news, notes, clock, battery 
status, etc.

Rainmeter uses a custom, language called Rainmeter Skin Language (RSL), to create and modify skins.
The language is object-oriented, similar to XML. Rainmeter is written in C++ and C# for Windows.

Rainmeter can be customized with .ini files, which can be edited with any text editor ,
and many skins have an options panel that allows changes to colors or other settings.

Learn more about Rainmeter in [docs](https://docs.rainmeter.net/manual/)

## <div style="color:#f59800" align="center">---| Table of Contents :bookmark_tabs: |---</div>
<!-- TOC -->
* [---| NeoGauge - System monitor widget for Windows |---</div>](#div-stylecolorf59800-aligncenter----neogauge---system-monitor-widget-for-windows----div)
   * [About this project:](#about-this-project)
   * [Scripting language:](#scripting-language)
* [---| Table of Contents :bookmark_tabs: |---](#div-stylecolorf59800-aligncenter----table-of-contents-bookmarktabs----div)
* [---| Screenshots |---](#screenshots)
* [---| Prerequisites :heavy_check_mark: |---](#div-stylecolorf59800-aligncenter----prerequisites-heavycheckmark----div)
* [---| Installation 🚀 |---](#div-stylecolorf59800-aligncenter----installation-----div)
* [---| Usage :computer: |---](#div-stylecolorf59800-aligncenter----usage-computer----div)
* [---| Configuration :wrench: |---</div>](#div-stylecolorf59800-aligncenter----configuration-wrench----div)
* [---| Built with 🛠️ |---](#div-stylecolorf59800-aligncenter----built-with-----div)
* [---| Contributing 🤝 |---](#div-stylecolorf59800-aligncenter----contributing-----div)
* [---| About Me 👨‍💻 |---](#div-stylecolorf59800-aligncenter----about-me-----div)
   * [---| Links 🔗|---](#div-stylecolorf59800-aligncenter----links----div)
   * [My Skill Set 👩‍💻](#my-skill-set-)
<!-- TOC -->









## Screenshots


---

![demo](https://raw.githubusercontent.com/NorbertRuff/NeoGauge/master/blob/demo.gif?raw=true)


---

![screenshot1](https://raw.githubusercontent.com/NorbertRuff/NeoGauge/master/blob/screenShot1.png?raw=true)
![screenshot2](https://raw.githubusercontent.com/NorbertRuff/NeoGauge/master/blob/screenShot2.png?raw=true)
![screenshot3](https://raw.githubusercontent.com/NorbertRuff/NeoGauge/master/blob/screenShot3.png?raw=true)

---


## <div style="color:#f59800" align="center">---| Prerequisites :heavy_check_mark: |---</div>

Prerequisites for this project are:
- Rainmeter
- Windows

- HWiNFO (optional) - for hardware temperature monitoring
- Rainmeter HWiNFO plugin


### Scripting language:
- Rainmeter Skin Language (RSL)
- Lua
- Ini



## <div style="color:#f59800" align="center">---| Installation 🚀 |---</div>

Installation steps:
1. Install Rainmeter from [here](https://www.rainmeter.net/)
2. Install HWiNFO from [here](https://www.hwinfo.com/download/)
3. Install Rainmeter HWiNFO plugin from [here](https://docs.rainmeter.net/tips/hwinfo/)
4. 
    - A. Download this repository and extract it to your Rainmeter skins folder (usually C:\Users\%username%\Documents\Rainmeter\Skins)
    - B. Or you can use the included Rainmeter skin installer by running the .rmskin file
5. Open Rainmeter and load the skin 
6. Customize the skin by starting the included configuration tool (config.ini) or by editing the .ini files in the skin folder
7. Enjoy!


## <div style="color:#f59800" align="center">---| Usage :computer: |---</div>

Hwinfo usage steps:
- Follow this [guide](https://docs.rainmeter.net/tips/hwinfo/) to install the HWiNFO plugin for Rainmeter
- Select all the sensors you want to monitor in rainmeter
- Open a terminal and run the following command: ` reg query HKEY_CURRENT_USER\SOFTWARE\HWiNFO64\VSB`
- You should see a list of all the sensors you selected in rainmeter
- Open the @Resources\settings.txt file and copy the sensor value to the corresponding variables
- Save the file and refresh the skin

## <div style="color:#f59800" align="center">---| Configuration :wrench: |---</div>
You can configure the skin by editing the included config.ini file or by editing the .ini files in the skin folder.
Each folder in the skin folder contains a .ini file that can be edited to customize the skin. 
the related style is located in the @Resources\Styles and @Resources\Apparance folders.

## <div style="color:#f59800" align="center">---| Built with 🛠️ |---</div>

- [Rainmeter](https://www.rainmeter.net/)
- [HWiNFO](https://www.hwinfo.com/download/)
- [Rainmeter HWiNFO plugin](https://www.hwinfo.com/forum/Thread-Rainmeter-plug-in-for-HWiNFO-3-0)
- [JetBrains IntelliJ IDEA](https://www.jetbrains.com/idea/)
- [❤️ and ☕]()



# <div style="color:#f59800" align="center">---| Contributing 🤝 |---</div>

Contributions, issues and feature requests are welcome!<br/>
Give a ⭐️ if this project helped you!

# <div style="color:#f59800" align="center">---| About Me 👨‍💻 |---</div>

<h2 align="center">Hi 👋, I'm Norbert</h2>
<h3 align="center">A passionate developer from Apex Lab Hungary</h3>

<p align="left"> <img src="https://komarev.com/ghpvc/?username=norbertruff&label=Profile%20views&color=0e75b6&style=flat" alt="norbertruff" /> </p>

- 🌱 I’m currently learning **React**

- 👨‍💻 All of my projects are available at [https://github.com/NorbertRuff](https://github.com/NorbertRuff)

- 📫 How to reach me **ruffnorbert88@gmail.com**

<h3 align="left">Connect with me:</h3>

## <div style="color:#f59800" align="center">---| Links 🔗|---</div>

[![portfolio](https://img.shields.io/badge/my_portfolio-000?style=for-the-badge&logo=ko-fi&logoColor=white)](https://github.com/NorbertRuff)

[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/ruff-norbert/)

<h2><img src="https://media.giphy.com/media/cj87CxfRtrUifF3Ryk/giphy.gif" height="25"> My Github Stats</h2>

<div align="center">

[![](https://raw.githubusercontent.com/NorbertRuff/NorbertRuff/master/profile-summary-card-output/material_palenight/0-profile-details.svg)](https://github.com/vn7n24fzkq/github-profile-summary-cards)

[![](https://raw.githubusercontent.com/NorbertRuff/NorbertRuff/master/profile-summary-card-output/material_palenight/1-repos-per-language.svg)](https://github.com/vn7n24fzkq/github-profile-summary-cards)
[![](https://raw.githubusercontent.com/NorbertRuff/NorbertRuff/master/profile-summary-card-output/material_palenight/2-most-commit-language.svg)](https://github.com/vn7n24fzkq/github-profile-summary-cards)
[![](https://raw.githubusercontent.com/NorbertRuff/NorbertRuff/master/profile-summary-card-output/material_palenight/3-stats.svg)](https://github.com/vn7n24fzkq/github-profile-summary-cards)

[![](https://raw.githubusercontent.com/NorbertRuff/NorbertRuff/master/profile-summary-card-output/dracula/4-productive-time.svg)](https://github.com/vn7n24fzkq/github-profile-summary-cards)

</div>

## My Skill Set 👩‍💻

<div align="center">  
<img src="https://www.codewars.com/users/NorbertRuff/badges/large">
</div>

<table style="border-collapse: collapse; width: 100%;" border="1">
  <tr>
    <td valign="top" width="25%">
      <h2 align="center"> 💻 </h2>
      <div align="center">
        <img src="https://img.shields.io/badge/Python-3776AB?style=flat-square&logo=python&logoColor=white" height="25">
        <img src="https://img.shields.io/badge/Java-ED8B00?style=flat-square&logo=java&logoColor=white" height="25">
        <img src="https://img.shields.io/badge/Go-00ADD8?style=flat-square&logo=go&logoColor=white" height="25">
        <img src="https://img.shields.io/badge/-GraphQL-E10098?style=flat-square&logo=graphql&logoColor=white" height="25">
        <img src="https://img.shields.io/badge/shell_script-%23121011?style=flat-square&logo=shell&logoColor=white" height="25">
        <img src="https://img.shields.io/badge/spring-%236DB33F?style=flat-square&logo=spring&logoColor=white" height="25">
        <img src="https://img.shields.io/badge/Svelte-4A4A55?style=flat-square&logo=svelte&logoColor=FF3E00" height="25">
        <img src="https://img.shields.io/badge/PostgreSQL-316192?style=flat-square&logo=postgresql&logoColor=white" height="25">
        <img src="https://img.shields.io/badge/-jest-%23C21325?style=flat-square&logo=jest&logoColor=white" height="25">
      </div>
    </td>
    <td valign="top" width="25%">
      <h2 align="center"> 🌐 </h2>
      <div align="center">
        <img src="https://img.shields.io/badge/-CSS3-1572B6?style=flat-square&logo=css3" height="25">
        <img src="https://img.shields.io/badge/HTML5-E34F26?style=flat-square&logo=html5&logoColor=white" height="25">
        <img src="https://img.shields.io/badge/React-20232A?style=flat-square&logo=react&logoColor=61DAFB" height="25">
        <img src="https://img.shields.io/badge/Bootstrap-563D7C?style=flat-square&logo=bootstrap&logoColor=white" height="25">
        <img src="https://img.shields.io/badge/JavaScript-F7DF1E?style=flat-square&logo=javascript&logoColor=black" height="25">
        <img src="https://img.shields.io/badge/TypeScript-007ACC?style=flat-square&logo=typescript&logoColor=white" height="25"> 
        <img src="https://img.shields.io/badge/Express.js-404D59?style=flat-square" height="25">
        <img src="https://img.shields.io/badge/Node.js-43853D?style=flat-square&logo=node.js&logoColor=white" height="25">
        <img src="https://img.shields.io/badge/GraphQL-E10098?style=flat-square&logo=graphql&logoColor=white" height="25">
        <img src="https://img.shields.io/badge/typescript-%23007ACC?style=flat-square&logo=typescript&logoColor=white" height="25">
        <img src="https://img.shields.io/badge/Flask-000000?style=flat-square&logo=flask&logoColor=white" height="25">
        <img src="https://img.shields.io/badge/nestjs-%23E0234E?style=flat-square&logo=nestjs&logoColor=white" height="25">
        <img src="https://img.shields.io/badge/node.js-6DA55F?style=flat-square&logo=node.js&logoColor=white" height="25">
        <img src="https://img.shields.io/badge/Thymeleaf-%23005C0F?style=flat-square&logo=Thymeleaf&logoColor=white" height="25">
        <img src="https://img.shields.io/badge/styled--components-DB7093?style=flat-square&logo=styled-components&logoColor=white" height="25">
        <img src="https://img.shields.io/badge/Material--UI-0081CB?style=flat-square&logo=material-ui&logoColor=white" height="25">
        <img src="https://img.shields.io/badge/NPM-%23CB3837.svg?style=for-the-badge&logo=npm&logoColor=white" height="25">
        <img src="https://img.shields.io/badge/Yarn-2C8EBB?style=flat-square&logo=yarn&logoColor=white" height="25">
</div>
    </td>
    <td valign="top" width="25%">
      <h2 align="center"> ⚙ </h2>
      <div align="center">
        <img src="https://img.shields.io/badge/-Linux-black?style=flat-square&logo=Linux" height="25">
        <img src="https://img.shields.io/badge/Windows-0078D6?style=flat-square&logo=windows&logoColor=white" height="25">
        <img src="https://img.shields.io/badge/NPM-%23000000?style=flat-square&logo=npm&logoColor=white" height="25">
        <img src="https://img.shields.io/badge/Ubuntu-E95420?style=flat-square&logo=ubuntu&logoColor=white" height="25">
        <img src="https://img.shields.io/badge/-Git-black?style=flat-square&logo=git" height="25">
        <img src="https://img.shields.io/badge/-GitHub-181717?style=flat-square&logo=github" height="25">
        <img src="https://img.shields.io/badge/githubactions-%232671E5?style=flat-square&logo=githubactions&logoColor=white" height="25">
        <img src="https://img.shields.io/badge/Markdown-000000?style=flat-square&logo=markdown&logoColor=white" height="25">
        <img src="https://img.shields.io/badge/pycharm-143?style=flat-square&logo=pycharm&logoColor=white" height="25">
        <img src="https://img.shields.io/badge/Visual%20Studio%20Code-0078d7?style=flat-square&logo=visual-studio-code&logoColor=white" height="25">
        <img src="https://img.shields.io/badge/webstorm-143?style=flat-square&logo=webstorm&logoColor=white" height="25">
        <img src="https://img.shields.io/badge/IntelliJ%20IDEA-000000.svg?style=flat-square&logo=intellij-idea&logoColor=white" height="25">
        <img src="https://img.shields.io/badge/PyCharm-143?style=flat-square&logo=pycharm&logoColor=white" height="25">
        <img src="https://img.shields.io/badge/GoLand-0f0f0f?&style=for-the-badge&logo=goland&logoColor=white" height="25">
        <img src="https://img.shields.io/badge/Anaconda-44A833?style=flat-square&logo=anaconda&logoColor=white" height="25">
        <img src="https://img.shields.io/badge/Postman-FF6C37?style=flat-square&logo=postman&logoColor=white" height="25">
        <img src="https://img.shields.io/badge/Insomnia-5849BE?style=flat-square&logo=insomnia&logoColor=white" height="25">
        <img src="https://img.shields.io/badge/Atom-%2366595C.svg?style=for-the-badge&logo=atom&logoColor=white" height="25">
        

</div>
    </td>
    <td valign="top" width="25%">
      <h2 align="center"> 🎨 </h2>
      <div align="center">
        <img src="https://aleen42.github.io/badges/src/photoshop.svg" height="25">
        <img src="https://aleen42.github.io/badges/src/illustrator.svg" height="25">
        <img src="https://aleen42.github.io/badges/src/dreamweaver.svg" height="25">
        <img src="https://aleen42.github.io/badges/src/flash.svg" height="25">
        <img src="https://aleen42.github.io/badges/src/after_effects.svg" height="25">
        <img src="https://aleen42.github.io/badges/src/premiere.svg" height="25">
</div>
    </td>
  </tr>
</table>



<div align="center">

<p align="center"> <img src="https://komarev.com/ghpvc/?username=NorbertRuff&label=Profile%20views&color=0e75b6&style=flat-square" alt="prathmesh" /> </p>


</div>
