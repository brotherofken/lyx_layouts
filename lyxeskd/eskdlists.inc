
# Standard textclass definition file. Taken from initial LyX source code
# Author : Matthias Ettrich <ettrich@informatik.uni-tuebingen.de>
# Transposed by Pascal André <andre@via.ecp.fr>
# Heavily modifed and enhanced by several developers.

# This include files contains various standard environments for lists.


Format 11
Style Itemize
	Category              List
	Margin                Static
	LatexType             Item_Environment
	LatexName             itemize
	NextNoIndent          1
	LeftMargin            MMN
	LabelSep              xx
	ItemSep               0.2
	TopSep                0.7
	BottomSep             0.7
	ParSep                0.3
	Align                 Block
	AlignPossible         Block, Left
	LabelType             Itemize
	LabelString           "*"
End


Style Enumerate
	Category              List
	Margin                Static
	LatexType             Item_Environment
	LatexName             enumerate
	NextNoIndent          1
	LeftMargin            MMN
	LabelSep              xx
	ParSkip               0.0
	ItemSep               0.2
	TopSep                0.7
	BottomSep             0.7
	ParSep                0.3
	Align                 Block
	AlignPossible         Block, Left
	LabelType             Enumerate
End


Style Description
	Category              List
	Margin                First_Dynamic
	LatexType             Item_environment
	LatexName             description
	NextNoIndent          1
	LeftMargin            MM
	LabelSep              xxx
	ParSkip               0.4
	ItemSep               0.2
	TopSep                0.7
	BottomSep             0.7
	ParSep                0.3
	Align                 Block
	AlignPossible         Block, Left
	LabelType             Manual
	LabelString           "MM"
	LabelFont
	  Series              Bold
	EndFont
End


Style List
	Category              List
	Margin                Manual
	LatexType             Environment
	LatexName             lyxlist
	NextNoindent          1
	LabelSep              xxx
	ParSkip               0.4
	TopSep                0.7
	BottomSep             0.7
	ParSep                0.5
	Align                 Block
	AlignPossible         Block, Left
	LabelType             Manual
	LabelString           "00.00.0000"

	#define the environment lyxlist
	Preamble
		\newenvironment{lyxlist}[1]
			{\begin{list}{}
				{\settowidth{\labelwidth}{#1}
				 \setlength{\leftmargin}{\labelwidth}
				 \addtolength{\leftmargin}{\labelsep}
				 \renewcommand{\makelabel}[1]{##1\hfil}}}
			{\end{list}}
	EndPreamble
End

# Новое окружение для составления листа регистрации изменений.
# Тут считаю необходимым переопределить item, с команды без параметров в команду с одним параметром.
# Буду передавать в \item{} строку и парсить её, используя пакет stringstrings.
# Лист регистрации изменений есть таблица, состаящая из десяти колонок.
# Необходимо отделять содержимое колонок друг от друга. В качество разделителя будем использоваться
# символ "\&".
# Алгоритм следующий:
# 1) Выхватить первое слово из строки, используя \getaword{}
# 2) Получить индекс символа \&, используя \whereischar{} - пусть это будем число i
# 3) Удалить первые i символов строки, используя \gobblechars{}
# Повторить с пункта 1 для оставшихся девяти слов.
# Поскольку некоторые колонки могут быть пустыми предлагаю использовать специальное слово для
# пустых колонок - nop. использовать \if и если слово - nop, заменять его пустым словом (пробелом)

Style ESCList
	Category              List
	Margin                Manual
	LatexType             List_Environment
	LatexName             ecslist
	NextNoindent          1
	LabelSep              xxx
	ParSkip               0.4
	TopSep                0.7
	BottomSep             0.7
	ParSep                0.5
	Align                 Block
	AlignPossible         Block, Left
	LabelType             Static

	#define the environment ecslist
	Preamble
		\newenvironment{ecslist}%
			{%
				\newcounter{ecscounter}%
				\setcounter{ecscounter}{1}%
				\let\olditem\item%
				\renewcommand{\item}[9]{%
					\arabic{ecscounter} & ##1 & ##2 & ##3 & ##4 & ##5 & ##6 & ##7 & ##8 & ##9 \\%
					\addtocounter{ecscounter}{1}}
				\begin{ESKDchangeSheet}%
			}%
			{\end{ESKDchangeSheet}}
	EndPreamble
End


Style Explanation
	Category              List
	Margin                First_Dynamic
	LatexType             Item_environment
	LatexName             ESKDexplanation
	NextNoIndent          1
	LeftMargin            MM
	LabelSep              xxx
	ParSkip               0.4
	ItemSep               0.2
	TopSep                0.7
	BottomSep             0.7
	ParSep                0.3
	Align                 Block
	AlignPossible         Block, Left
	LabelType             Manual
	LabelString           "MM"
	LabelFont
	  Series              Bold
	EndFont
End
