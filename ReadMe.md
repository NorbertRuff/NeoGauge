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

Rainmeter can be customized with .ini files and lua scripts, which can be edited with any text editor.

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
* [---| Performance :chart_with_upwards_trend: |---](#div-stylecolorf59800-aligncenter----performance-chartwithupwardstrend----div)
* [---| Built with 🛠️ |---](#div-stylecolorf59800-aligncenter----built-with-----div)
* [---| Contributing 🤝 |---](#div-stylecolorf59800-aligncenter----contributing-----div)
* [---| About Me 👨‍💻 |---](#div-stylecolorf59800-aligncenter----about-me-----div)
<!-- TOC -->









## Screenshots


---

![demo](https://raw.githubusercontent.com/NorbertRuff/NeoGauge/master/blob/demo.gif?raw=true)


---

![screenshot1](https://raw.githubusercontent.com/NorbertRuff/NeoGauge/master/blob/screenShot1.png?raw=true)
![screenshot2](https://raw.githubusercontent.com/NorbertRuff/NeoGauge/master/blob/screenShot2.png?raw=true)
![screenshot3](https://raw.githubusercontent.com/NorbertRuff/NeoGauge/master/blob/screenshot3.png?raw=true)

---


## <div style="color:#f59800" align="center">---| Prerequisites :heavy_check_mark: |---</div>

- Windows 10 or 11
- [Rainmeter](https://www.rainmeter.net/) 4.5 or newer
- [HWiNFO](https://www.hwinfo.com/download/) (optional) - only for the temperature, fan and pump gauges

The Ubuntu Nerd Font used by the gauges ships in `@Resources\Fonts` and loads automatically; nothing to install.

### Scripting language:
- Rainmeter Skin Language
- Lua
- Ini



## <div style="color:#f59800" align="center">---| Installation 🚀 |---</div>

1. Install [Rainmeter](https://www.rainmeter.net/)
2. Get the skin, either way:
    - Download this repository into your Rainmeter skins folder (usually `C:\Users\%username%\Documents\Rainmeter\Skins\NeoGauge`)
    - Or run the included `.rmskin` installer
3. Open Rainmeter's Manage window and load the gauges you want from the `NeoGauge` folder
4. Load `NeoGauge\Config.ini` to set everything up (see [Configuration](#div-stylecolorf59800-aligncenter----configuration-wrench----div))
5. Optional: set up HWiNFO for the temperature and fan gauges (see [Usage](#div-stylecolorf59800-aligncenter----usage-computer----div))

### Display scaling (125 % / 150 % / 200 %)

Rainmeter does not handle Windows display scaling itself, so on a scaled display Windows stretches the skins and they look blurry. For sharp gauges:

1. Right-click `C:\Program Files\Rainmeter\Rainmeter.exe` > **Properties** > **Compatibility** > **Change high DPI settings**
2. Tick **Override high DPI scaling behavior**, set it to **Application**, and restart Rainmeter
3. In the config tool's **system** page, set **Display scale** to your Windows scale (e.g. 200 %)

Every gauge, font and the config window scale from that one setting. If your gauges jump to new spots after step 2, drag them back once.


## <div style="color:#f59800" align="center">---| Usage :computer: |---</div>

The temperature, fan and pump gauges read sensors from HWiNFO through the Windows registry:

1. In HWiNFO's sensors window, open **Settings** > **HWiNFO Gadget**, select each sensor you want and tick **Report value in Gadget**
2. Keep HWiNFO running
3. Open a terminal and run `reg query HKEY_CURRENT_USER\SOFTWARE\HWiNFO64\VSB` to see the reported sensors: each has a `LabelN` and a `ValueN`
4. In `@Resources\Settings.txt`, set the matching variables (`cpuTemp1=Value1`, `fan1rpm=Value7`, `fan1RawRpm=ValueRaw7`, ...) and the display labels
5. Refresh the skins

The numbers follow the order of the sensors you enabled in HWiNFO, so adding or removing a sensor there can shift them.

Other handy interactions:
- Hover a gauge's main text for a tooltip with its peak values since load; right-click it to reset them
- Click the CPU text to open Task Manager, a disk's text to open the drive


## <div style="color:#f59800" align="center">---| Configuration :wrench: |---</div>

Load `Config.ini` (the `NeoGauge` root skin) for the settings window. Every click applies right away and the current choice is highlighted:

- **appearance** - pick a gauge group at the top (cpu, ram, I/O, disks, temps & fans, download, upload, wifi, battery, other), then set its orientation, size, margins, font style, colors (click a color to type a new one, click the bar to set its opacity), color presets, and which parts of the ring to show
- **effects** - how the rings move, for every gauge at once:
    - presets: **off** (jump once a second, the lightest), **light**, **balanced**, **everything**
    - **smooth** motion and its speed
    - **glow**: off, always, or growing with load (55-90 %), at three strengths
    - **peak hold**: a tick marks the recent high, then slides back
    - **afterglow**: drops fade out instead of vanishing
    - **comet**: the arc brightens toward a glowing tip (the heaviest effect)
    - **round ends** on the arc
- **system** - display scale, fonts, the drive letters for the five disk gauges, your connection speed (the network gauges show traffic as a share of it), the fan RPM that counts as 100 %, and the recycle bin size (plus an opt-in to empty it automatically when full)
- **time** - what the clock's ring tracks (minute to year) and the time and date formats

Gauges turn yellow from 75 % and red from 90 % (not battery, wifi, volume or clock).

Animated effects only run while a ring is moving, then go idle. If Rainmeter's CPU use matters to you, use the **light** or **off** preset.

Everything is stored in plain text files that you can also edit by hand ("edit files" in the config window opens them):
- `@Resources\Settings.txt` - system, time and effects settings, HWiNFO sensors
- `@Resources\Apparence\*.txt` - one appearance file per gauge group


## <div style="color:#f59800" align="center">---| Performance :chart_with_upwards_trend: |---</div>

Rainmeter's own CPU and RAM use with the same 17 gauges loaded, version 1.0 (`master`) against 2.0 (`update`, **balanced** effects):

| | 1.0 (`master`) | 2.0, effects **balanced** | 2.0, effects **off** |
|---|---|---|---|
| CPU, average | ~52 % of one core (3.2 % of total) | ~17 % of one core (1.1 % of total) | ~5 % of one core (0.3 % of total) |
| CPU, busiest seconds (95th percentile) | 57-59 % of one core | 48-65 % of one core | ~16 % of one core |
| RAM in use (working set) | 55 MB | 66-67 MB | ~71 MB |
| RAM owned by Rainmeter (private) | 26-27 MB | ~32 MB | - |

- **CPU is much lower on average** mainly because the CPU gauge's "top process" check (the old AdvancedCPU plugin, the most expensive measure in the suite) runs every 30 s instead of every 3 s. Other updates are also trimmed to what's visible:
  - HWiNFO sensors are read every 2 s, as often as HWiNFO refreshes them.
  - The background bar draws once and never updates.
  - Uptime updates every 10 s, since it shows only minutes.
- **The ring animations are most of what's left** (~12 % of one core on average with balanced). A gauge redraws 20 times a second only while its ring moves, then goes idle, so busy gauges (CPU, network, disk activity) cause the peaks. The **light** or **off** preset removes most of that cost.
- **RAM is ~10 MB higher** than 1.0: 2.0 draws the gauges at full display resolution (4x the pixels at 200 % scaling) and adds the effect meters and a small Lua script per gauge.

How it was measured (2026-10-14): Rainmeter 4.5.28 64-bit, Windows 11 Pro 25H2, Intel i7-10700K (16 threads), 200 % display scaling with Rainmeter's high-DPI override on. Rainmeter was restarted, left to settle for 20 s, then sampled once a second for 60 s: 2 runs on 1.0, 2 runs on 2.0 balanced, 1 run on 2.0 off. The PC was in normal use (browser, IDE), so expect some spread between runs. Loaded gauges: CPU, RAM, disk activity, disks 1-5, download, upload, CPU and GPU temperature, fans 2-4, uptime, background bar.


## <div style="color:#f59800" align="center">---| Built with 🛠️ |---</div>

- [Rainmeter](https://www.rainmeter.net/)
- [HWiNFO](https://www.hwinfo.com/download/)
- [Ubuntu Nerd Font](https://www.nerdfonts.com/) (Ubuntu Font Licence)
- [JetBrains IntelliJ IDEA](https://www.jetbrains.com/idea/)
- [❤️ and ☕]()



# <div style="color:#f59800" align="center">---| Contributing 🤝 |---</div>

Contributions, issues and feature requests are welcome!<br/>
Give a ⭐️ if this project helped you!

# <div style="color:#f59800" align="center">---| About Me 👨‍💻 |---</div>

<h2 align="center">Hi 👋, I'm Norbert</h2>
<h3 align="center">A passionate developer from Apex Lab Hungary</h3>

- 👨‍💻 All of my projects are available at [https://github.com/NorbertRuff](https://github.com/NorbertRuff)

[![github](https://img.shields.io/badge/github-000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/NorbertRuff)
[![LinkedIn](https://img.shields.io/badge/-linkedin-blue?style=for-the-badge&logo=linkedin&logoColor=white&link=https://www.linkedin.com/in/ruff-norbert-6b167b204//)](https://www.linkedin.com/in/ruff-norbert-6b167b204/)
[![Gmail Badge](https://img.shields.io/badge/-Mail-c14438?style=for-the-badge&logo=Gmail&logoColor=white&link=mailto:ruffnorbert88@gmail.com)](mailto:ruffnorbert88@gmail.com)


# <div style="color:#f59800" align="center">---| My Stats <img src="https://media.giphy.com/media/cj87CxfRtrUifF3Ryk/giphy.gif" height="25"> |---</div>


[![](https://raw.githubusercontent.com/NorbertRuff/NorbertRuff/master/profile-summary-card-output/material_palenight/0-profile-details.svg)](https://github.com/vn7n24fzkq/github-profile-summary-cards)
[![](https://raw.githubusercontent.com/NorbertRuff/NorbertRuff/master/profile-summary-card-output/material_palenight/1-repos-per-language.svg)](https://github.com/vn7n24fzkq/github-profile-summary-cards)
[![](https://raw.githubusercontent.com/NorbertRuff/NorbertRuff/master/profile-summary-card-output/material_palenight/2-most-commit-language.svg)](https://github.com/vn7n24fzkq/github-profile-summary-cards)
[![](https://raw.githubusercontent.com/NorbertRuff/NorbertRuff/master/profile-summary-card-output/material_palenight/3-stats.svg)](https://github.com/vn7n24fzkq/github-profile-summary-cards)
[![](https://raw.githubusercontent.com/NorbertRuff/NorbertRuff/master/profile-summary-card-output/dracula/4-productive-time.svg)](https://github.com/vn7n24fzkq/github-profile-summary-cards)

</div>

## 🛠️

<div align="center">
    <img src="https://www.codewars.com/users/NorbertRuff/badges/large" alt="codewars"/>
</div>

<table style="border-collapse: collapse; width: 100%;" border="1">
    <tr>
        <td valign="top">
            <h2 align="center"> 💻 </h2>
            <div align="center">
                <img src="https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white" height="25" alt="python">
                <img src="https://img.shields.io/badge/java-%23ED8B00.svg?style=for-the-badge&logo=openjdk&logoColor=white" height="25" alt="java">
                <img src="https://img.shields.io/badge/Go-00ADD8?style=for-the-badge&logo=go&logoColor=white" height="25" alt="go">
                <img src="https://img.shields.io/badge/css3-%231572B6.svg?style=for-the-badge&logo=css3&logoColor=white" height="25" alt="css">
                <img src="https://img.shields.io/badge/HTML5-%23E34F26.svg?style=for-the-badge&logo=html5&logoColor=white" height="25" alt="html">
                <img src="https://img.shields.io/badge/JavaScript-%23F7DF1E.svg?style=for-the-badge&logo=javascript&logoColor=black" height="25" alt="javascript">
                <img src="https://img.shields.io/badge/TypeScript-%23007ACC.svg?style=for-the-badge&logo=typescript&logoColor=white" height="25" alt="typescript">
                <img src="https://img.shields.io/badge/Markdown-000000?style=for-the-badge&logo=markdown&logoColor=white" height="25" alt="markdown">
            </div>
        </td>
        <td valign="top">
            <h2 align="center"> 🌐 </h2>
            <div align="center">
                <img src="https://img.shields.io/badge/React-20232A?style=for-the-badge&logo=react&logoColor=61DAFB" height="25" alt="react">
                <img src="https://img.shields.io/badge/node.js-6DA55F?style=for-the-badge&logo=node.js&logoColor=white" height="25" alt="nodejs">
                <img src="https://img.shields.io/badge/GraphQL-E10098?style=for-the-badge&logo=graphql&logoColor=white" height="25" alt="graphql">
                <img src="https://img.shields.io/badge/Prisma-3982CE?style=for-the-badge&logo=Prisma&logoColor=white" height="25" alt="Prisma">
                <img src="https://img.shields.io/badge/express.js-%23404d59.svg?style=for-the-badge&logo=express&logoColor=%2361DAFB" height="25" alt="express">
                <img src="https://img.shields.io/badge/svelte-%23f1413d.svg?style=for-the-badge&logo=svelte&logoColor=white" height="25" alt="svelte">
                <img src="https://img.shields.io/badge/nestjs-%23E0234E?style=for-the-badge&logo=nestjs&logoColor=white" height="25" alt="nestjs">
                <img src="https://img.shields.io/badge/flask-%23000.svg?style=for-the-badge&logo=flask&logoColor=white" height="25" alt="flask">
                <img src="https://img.shields.io/badge/Thymeleaf-%23005C0F?style=for-the-badge&logo=Thymeleaf&logoColor=white" height="25" alt="thymeleaf">
                <img src="https://img.shields.io/badge/jinja-white.svg?style=for-the-badge&logo=jinja&logoColor=black" height="25" alt="jinja">
                <img src="https://img.shields.io/badge/-ApolloGraphQL-311C87?style=for-the-badge&logo=apollo-graphql" height="25" alt="graphql">
                <img src="https://img.shields.io/badge/-Hasura-311C87?style=for-the-badge&logo=hasura" height="25" alt="hasura">
            </div>
        </td>
        <td valign="top">
            <h2 align="center"> 📚 </h2>
            <div align="center">
                <img src="https://img.shields.io/badge/Bootstrap-563D7C?style=for-the-badge&logo=bootstrap&logoColor=white" height="25" alt="bootstrap">
                <img src="https://img.shields.io/badge/styled--components-DB7093?style=for-the-badge&logo=styled-components&logoColor=white" height="25" alt="styled-components">
                <img src="https://img.shields.io/badge/MUI-%230081CB.svg?style=for-the-badge&logo=mui&logoColor=white" height="25" alt="material-ui">
                <img src="https://img.shields.io/badge/NPM-%23CB3837.svg?style=for-the-badge&logo=npm&logoColor=white" height="25" alt="npm">
                <img src="https://img.shields.io/badge/yarn-%232C8EBB.svg?style=for-the-badge&logo=yarn&logoColor=white" height="25" alt="yarn">
                <img src="https://img.shields.io/badge/-jest-%23C21325?style=for-the-badge&logo=jest&logoColor=white" height="25" alt="jest">
                <img src="https://img.shields.io/badge/ESLint-4B3263?style=for-the-badge&logo=eslint&logoColor=white" height="25" alt="eslint">
                <img src="https://img.shields.io/badge/Postman-FF6C37?style=for-the-badge&logo=postman&logoColor=white" height="25" alt="postman">
                <img src="https://img.shields.io/badge/-Swagger-%23Clojure?style=for-the-badge&logo=swagger&logoColor=white" height="25" alt="swagger">
                <img src="https://img.shields.io/badge/chakra-%234ED1C5.svg?style=for-the-badge&logo=chakraui&logoColor=white" height="25" alt="chakra">
                <img src="https://img.shields.io/badge/fitbit-00B0B9?style=for-the-badge&logo=fitbit&logoColor=white" height="25" alt="fitbit">
            </div>
        </td>
        <td valign="top">
            <h2 align="center"> ⚙ </h2>
            <div align="center">
                <img src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" height="25" alt="linux">
                <img src="https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white" height="25" alt="ubuntu">
                <img src="https://img.shields.io/badge/webstorm-3982CE?style=for-the-badge&logo=webstorm&logoColor=white&color=3982CE" height="25" alt="webstorm">
                <img src="https://img.shields.io/badge/pycharm-3982CE?style=for-the-badge&logo=pycharm&logoColor=black&color=3982CE&labelColor=white" height="25" alt="pycharm">
                <img src="https://img.shields.io/badge/IntelliJIDEA-3982CE.svg?style=for-the-badge&logo=intellij-idea&logoColor=white" height="25" alt="intellij">
                <img src="https://img.shields.io/badge/GoLand-3982CE?&style=for-the-badge&logo=goland&logoColor=white" height="25" alt="Goland">
                <img src="https://img.shields.io/badge/Atom-%2366595C.svg?style=for-the-badge&logo=atom&logoColor=white" height="25" alt="Atom">
                <img src="https://img.shields.io/badge/Notepad++-90E59A.svg?style=for-the-badge&logo=notepad%2b%2b&logoColor=black" height="25" alt="notepad">
                <img src="https://img.shields.io/badge/Visual%20Studio%20Code-0078d7?style=for-the-badge&logo=visual-studio-code&logoColor=white" height="25">
            </div>
        </td>
        <td valign="top">
            <h2 align="center"> 🗄️ </h2>
            <div align="center">
                <img src="https://img.shields.io/badge/redis-%23DD0031.svg?style=for-the-badge&logo=redis&logoColor=white" height="25" alt="redis">
                <img src="https://img.shields.io/badge/postgres-%23316192.svg?style=for-the-badge&logo=postgresql&logoColor=white" height="25" alt="postgresql">
                <img src="https://img.shields.io/badge/circle%20ci-%23161616.svg?style=for-the-badge&logo=circleci&logoColor=white" height="25" alt="circleci">
                <img src="https://img.shields.io/badge/github%20actions-%232671E5.svg?style=for-the-badge&logo=githubactions&logoColor=white" height="25" alt="githubactions">
                <img src="https://img.shields.io/badge/AWS-%23FF9900.svg?style=for-the-badge&logo=amazon-aws&logoColor=white" height="25" alt="aws">
                <img src="https://img.shields.io/badge/heroku-%23430098.svg?style=for-the-badge&logo=heroku&logoColor=white" height="25" alt="heroku">
                <img src="https://img.shields.io/badge/docker-%230db7ed.svg?style=for-the-badge&logo=docker&logoColor=white" height="25" alt="docker">
                <img src="https://img.shields.io/badge/terraform-%235835CC.svg?style=for-the-badge&logo=terraform&logoColor=white" height="25" alt="terraform">
                <img src="https://img.shields.io/badge/bitbucket-%230047B3.svg?style=for-the-badge&logo=bitbucket&logoColor=white" height="25" alt="bitbucket">
                <img src="https://img.shields.io/badge/git-%23F05033.svg?style=for-the-badge&logo=git&logoColor=white" height="25" alt="git">
                <img src="https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white" height="25" alt="github">
            </div>
        </td>
        <td valign="top">
            <h2 align="center"> 🎨 </h2>
            <div align="center">
                <img src="https://aleen42.github.io/badges/src/photoshop.svg" height="25" alt="photoshop">
                <img src="https://aleen42.github.io/badges/src/illustrator.svg" height="25" alt="illustrator">
                <img src="https://aleen42.github.io/badges/src/dreamweaver.svg" height="25" alt="dreamweaver">
                <img src="https://aleen42.github.io/badges/src/flash.svg" height="25" alt="flash">
                <img src="https://aleen42.github.io/badges/src/after_effects.svg" height="25" alt="after effects">
                <img src="https://aleen42.github.io/badges/src/premiere.svg" height="25" alt="premiere">
            </div>
        </td>
    </tr>
</table>

<div align="center">
    <p align="center"><img src="https://komarev.com/ghpvc/?username=NorbertRuff&label=visitors&color=0e75b6&style=for-the-badge" alt="prathmesh"/></p>
</div>
