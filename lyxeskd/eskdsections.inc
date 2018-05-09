# Standard textclass definition file. Taken from initial LyX source code
# Author : Matthias Ettrich <ettrich@informatik.uni-tuebingen.de>
# Transposed by Pascal André <andre@via.ecp.fr>
# Heavily modifed and enhanced by several developers.

# This include files contains all numbered sectionning-related
# commands that are useful for article-like document classes, but not
# for letters.

Format 11
#Style Part
#	Category              Section
#	Margin                Dynamic
#	LabelString	          "Part \thepart"
#	LabelType	            Counter
#	TocLevel              0
#	LabelCounter	        part
#	LatexType             Command
#	LatexName             part
#	NeedProtect           1
#	NextNoIndent          1
#	Labelsep              xxx
#	ParSkip               0.4
#	TopSep                4
#	BottomSep             4
#	ParSep                0.8
#	Align                 Center
#	Alignpossible         Center
#	Font
#	  Series              Bold
#	  Size                Huge
#	EndFont
#End

#Style Chapter
#	Margin                Static
#	Category              Section
#	LabelString	          "Chapter \thechapter"
#	LabelStringAppendix   "Appendix \thechapter"
#	LabelType	            Counter
#	LabelCounter	        chapter
#	TocLevel              0
#	LatexType             Command
#	LatexName             chapter
#	NeedProtect           1
#	NextNoIndent          1
#	ParSkip               0.4
#	TopSep                4
#	BottomSep             0.8
#	ParSep                0.8
#	Align                 Block
#	OptionalArgs          1
#	Font
#	  Series              Bold
#	  Size                Huge
#	EndFont
#End


Style "Раздел"
	Category              "Раздел"
	Margin                Dynamic
	LabelType             Counter
	LabelCounter          section
	TocLevel              1
	LatexType             Command
	LatexName             section
	NeedProtect           1
	NextNoIndent          1
	LabelSep              xxx
	ParSkip               0.4
	TopSep                1.3
	BottomSep             0.7
	ParSep                0.7
	Align                 Block
	AlignPossible         Block, Left
	OptionalArgs          1
	Font
	  Series              Bold
	  Size                Larger
	EndFont
End


Style "Подраздел"
	CopyStyle             "Раздел"
	LabelCounter	      subsection
	TocLevel              2
	LatexName             ESKDsubsection
	TopSep                0.9
	BottomSep             0.5
	ParSep                0.5
	Font
	  Series              Bold
	  Size                Large
	EndFont
	
	Preamble
		\newcommand{\ESKDsubsection}[1]{
			\subsection{#1}
			\setcounter{point}{\value{subsection}}
			\setcounter{subpoint}{0}
		} 
	EndPreamble

End

# Поскольку в ЕСКД могут быть документы как с подразделами, так и без подразделов
# считаю логичным ввести 2 типа пунктов/подпунктов:
# 1) Для документов БЕЗ подразделов - начинаются префиксом woss(without subsections) 
#  (wossPoint, wossSubPoint)
# 2) Для документов ИМЕЮЩИХ подраздела - начинаются прфексом wss(with subsections)
#  (wssPoint, wssSubPoint)
#  так же необходимо разнести и в разные категории, чтобы в UI Lyx можно было выбрать их
# без лишней путаницы. 
# Для woss - "Без подразделов"
# Для wss - "С подразделами"
# Само собой они будут использоваться разные счетчики: 
# 1) 2 и 3 уровня для wss - subsection и point
# 2) 3 и 4 уровня для woss - point и subpoint
# Так же необходимо выделять заголовки для SubSection и не выбелять для point и subpoint,
# но выводить нумерацию.

Style "Пункт1"
	Category              "С подразделами"
	Margin                Dynamic
	LabelType             Counter
	LabelCounter          point
	KeepEmpty             1
	TocLevel              3
	LatexType             Command
	LatexName             subpoint
#	LatexParam            1
	NeedProtect           0
	NextNoIndent          0
	LabelSep              xxx
	ParSkip               0.4
	TopSep                0.4
	BottomSep             0
End


Style "Подпункт1"
	Category              "С подразделами"
	Margin                Dynamic
	LabelType             Counter
	LabelCounter          subpoint
	KeepEmpty             1
	TocLevel              3
	LatexType             Command
	LatexName             subsubpoint
#	LatexParam            1
	NeedProtect           0
	NextNoIndent          0
	LabelSep              xxx
	ParSkip               0.4
	TopSep                0.4
	BottomSep             0
End

Style "Пункт2"
	Category              "Без подразделов"
	Margin                Dynamic
	LabelType             Counter
	LabelCounter          subsection
	KeepEmpty             1
	TocLevel              3
	LatexType             Command
	LatexName             point
	NeedProtect           0
	NextNoIndent          0
	LabelSep              xxx
	ParSkip               0.4
	TopSep                0.4
	BottomSep             0
End

Style "Подпункт2"
	Category              "Без подразделов"
	Margin                Dynamic
	LabelType             Counter
	LabelCounter          point
	KeepEmpty             1
	TocLevel              3
	LatexType             Command
	LatexName             subpoint
	NeedProtect           0
	NextNoIndent          0
	LabelSep              xxx
	ParSkip               0.4
	TopSep                0.4
	BottomSep             0
End

# Поскольку команда ESKDappendix содержит 2 параметра, а передать в команду через Lyx
# мы можем только один документ, то необходимо применить одну старую рыбацкую хитрость,
# которую практиковал мой дедушка.
# Объявим в преамбуле новую команду ESKDappendixOP и будем передавать в неё строку следующего
# вида:
# "{обязательное|рекомендуемое|справочное} Заголовок приложения" 
# Используем пакет stringstrings. 
# 1) Используя макрос \getaword выхватим первое слово из входящей строки будем использовать его как
#  первый параметр для функции ESKDappendix.
# 2) Потом удалить из входящей строки первое слово (которое уже извлечено ранее) и остатки строки 
#  использовать как второй аргумент ESKDappendix.
# Вот такой я умник.

#%	Category              Section
#%	Margin                Dynamic
#%	LabelType             Counter
#%	LabelCounter          section

Style "Обязательное"
    Category              "Приложение"
    Margin                Dynamic
    LabelType             Static
    LabelString           "Прил. Обязат. "
    LabelCounter          appendix
    TocLevel              1
    LatexType             Command
    LatexName             ESKDappendixReq
    NeedProtect           1
    NextNoIndent          1
    LabelSep              xxx
    ParSkip               0.4
    TopSep                1.3
    BottomSep             0.7
    ParSep                0.7
    Align                 Block
    AlignPossible         Block, Left
    OptionalArgs          2
    Font
      Series              Bold
      Size                Larger
    EndFont

    Preamble
        \newcommand{\ESKDappendixReq}[1]{
            \ESKDappendix{"Обязательное"}{#1} 
        }
    EndPreamble
End

Style "Справочное"
    CopyStyle             "Обязательное"
    LabelString           "Прил. Справоч. "
    LatexName             ESKDappendixRef

    Preamble
        \newcommand{\ESKDappendixRef}[1]{
            \ESKDappendix{"Справочное"}{#1} 
        }
    EndPreamble
End

Style "Рекомендуемое"
    CopyStyle             "Обязательное"
    LabelString           "Прил. Рекоменд. "
    LatexName             ESKDappendixRec
    Preamble
        \newcommand{\ESKDappendixRec}[1]{
            \ESKDappendix{"Рекомендуемое"}{#1} 
        }
    EndPreamble
End


Input numarticle.inc
