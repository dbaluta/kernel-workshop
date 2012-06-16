% 2012, Razvan Deaconescu, razvan@rosedu.org
%
% Based on osss, based itself on so.cs.pub.ro by Vlad
% Dogaru, 2010, based itself on thesis.cs.pub.ro, by Mircea Bardac.
%
% workshop.cls - class for ROSEdu Summer Workshops

\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{workshop}[2012/06/14]

\LoadClassWithOptions{beamer}

% uncomment the lines bellow for Romanian Language support
% Use UTF8 file encoding when writing .tex files in Romanian
% Romanian Language support
\usepackage{ucs}
\usepackage[utf8x]{inputenc}
\PrerenderUnicode{aâîțșĂÎÂȚȘ}
\usepackage[english,romanian]{babel}
\usepackage{color}	  % if we need highlight
\usepackage{alltt}	  % if we need highlight
\usepackage{hyperref}	  % use \url{http://$URL} or \href{http://$URL}{Name}
\usepackage{underscore}	  % underscores need not be escaped
\usepackage{booktabs}     % nice looking tables

\mode<presentation>
{ \usetheme{Workshop} }

% Support for including graphics
\usepackage{graphicx}
\DeclareGraphicsExtensions{.pdf,.png,.jpg}

% So that we don't have to declare it a bazillion times
\institute[Workshop]{ROSEdu Summer Workshops}

% Slide-urile cu mai multe părți sunt marcate cu textul (cont.)
\setbeamertemplate{frametitle continuation}[from second]

% Fix verbatim environment: smaller text size
\let\oldverbatim=\verbatim
\renewenvironment{verbatim}{
  \begin{small}
  \begin{oldverbatim}
  %\vspace*{1em}
}%
{%
  %\vspace*{1em}
  \end{oldverbatim}
  \end{small}
}

% command for specifying TODOs
\newcommand{\todo}[1]{
  \textbf{TODO:} #1 \par
}

% command for formatting file or directory names
\newcommand{\file}[1]{\texttt{#1}}

% command for formatting inline commands
\newcommand{\cmd}[1]{\textbf{\texttt{#1}}}
% command for formatting inline function names
\newcommand{\func}[1]{\textbf{\texttt{#1}}}

\renewcommand{\arraystretch}{1.3}

% Show contents at every section beginning. Ripped off from manual.
\AtBeginSection[] % Do nothing for \section*
{
  \begin{frame}<beamer>
    \frametitle{Cuprins}
  \tableofcontents[currentsection]
    \end{frame}
}
