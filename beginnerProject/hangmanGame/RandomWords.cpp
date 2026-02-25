#include "RandomWords.h"
#include <string>
#include <vector>
#include <random>
using namespace std;

vector<WordData> randomWordsLibrary = {
    {"laptop", "A portable computer."},
    {"wifi", "Wireless networking technology."},
    {"internet", "Global network of computers."},
    {"coding", "The process of writing computer programs."},
    {"programmer", "A person who writes software."},
    {"hacker", "Someone who gains unauthorized access to data."},
    {"virus", "Malicious software that replicates itself."},
    {"application", "A program designed for a specific task."},
    {"website", "A set of related web pages."},
    {"email", "Electronic mail."},
    {"password", "A secret word to gain access."},
    {"login", "To enter a username and password."},
    {"logout", "To end a session on a computer."},
    {"download", "To receive data from a remote system."},
    {"upload", "To send data to a remote system."},
    {"file", "A resource for storing information."},
    {"folder", "A container for files."},
    {"keyboard", "An input device with keys."},
    {"mouse", "A hand-held pointing device."},
    {"screen", "The display part of a monitor."},
    {"monitor", "A screen used to display output."},
    {"charger", "A device for charging batteries."},
    {"battery", "An energy storage device."},
    {"zoom", "Popular video conferencing software."},
    {"google", "The most popular search engine."},
    {"youtube", "Video sharing platform."},
    {"instagram", "Photo and video sharing social media."},
    {"tiktok", "Short-form video social media."},
    {"chatgpt", "An AI chatbot by OpenAI."},
    {"AI", "Artificial Intelligence."},
    {"robot", "An automated machine."},
    {"smartphone", "A mobile phone with advanced features."},
    {"handphone", "Another word for mobile phone."},
    {"flashdisk", "Portable USB storage device."},
    {"powerpoint", "Presentation software by Microsoft."},
    {"excel", "Spreadsheet software by Microsoft."},
    {"word", "Word processing software by Microsoft."},
    {"printer", "Device to produce physical copies of documents."},
    {"scanner", "Device to digitize physical documents."},
    {"bug", "An error in a software program."},
    {"database", "Organized collection of data."},
    {"server", "A computer providing services to other computers."},
    {"hardware", "Physical components of a computer."},
    {"software", "Non-physical programs of a computer."},
    {"browser", "Software used to access the web."},
    {"firewall", "Network security system."},
    {"algorithm", "A set of rules or steps to solve a problem."},
    {"cloud", "On-demand availability of computer system resources."},
    {"pixel", "The smallest unit of a digital image."},
    {"bit", "The most basic unit of information in computing."},
    {"task", "Academic assignment."},
    {"deadline", "The latest time to finish something."},
    {"test", "A formal test of knowledge."},
    {"grade", "Academic grade or score."},
    {"lecturer", "A university teacher."},
    {"semester", "A half-year term in school or college."},
    {"skripsi", "Undergraduate thesis."},
    {"library", "A place containing collections of books."},
    {"campus", "The grounds and buildings of a university."},
    {"scholarship", "Financial aid for students."},
    {"research", "Systematic investigation into a subject."},
    {"journal", "A periodical publication on an academic subject."},
    {"abstract", "A short summary of a research paper."},
    {"degree", "An academic rank awarded by a college."},
    {"diploma", "A certificate awarded by an educational institution."},
    {"lecture", "An educational talk to an audience of students."},
    {"seminar", "A small group discussion in a university."},
    {"laboratory", "A room for scientific experiments."},
    {"internship", "A period of work experience for students."},
    {"graduate", "A person who has successfully finished their studies."},
    {"freshman", "A first-year student."},
    {"sophomore", "A second-year student."},
    {"junior", "A third-year student."},
    {"senior", "A fourth-year student."},
    {"major", "The main subject studied by a student."},
    {"minor", "A secondary subject studied by a student."},
    {"faculty", "A group of university departments."},
    {"curriculum", "The subjects comprising a course of study."},
    {"syllabus", "An outline of the subjects in a course."},
    {"presentation", "Showing or explaining a topic to an audience."},
    {"notebook", "A book with blank pages for writing notes."},
    {"backpack", "A bag used for carrying books."},
    {"dormitory", "A building for students to live in."},
    {"textbook", "A book used as a standard work for a study."},
    {"dictionary", "A book listing words and their meanings."},
    {"thesaurus", "A book listing words with similar meanings."},
    {"calculator", "A device for performing mathematical calculations."},
    {"microscope", "An instrument for seeing tiny objects."},
    {"telescope", "An instrument for seeing distant objects."},
    {"assignment", "A task or piece of work allocated to someone."},
    {"certificate", "An official document attesting a fact."},
    {"dean", "The head of a university faculty."},
    {"rector", "The head of some universities."},
    {"procrastination", "Delaying or postponing something."},
    {"plagiarism", "Taking someone else's work as your own."},
    {"reference", "A source used in research."},
    {"citation", "A quotation from or reference to a source."},
    {"tuition", "Money paid for teaching or instruction."},
};


RandomWords::RandomWords() {
    chooseRandomWord();
}

void RandomWords::chooseRandomWord() {
    int randomIndex = (rand() % randomWordsLibrary.size());
    this->selectedWord = randomWordsLibrary[randomIndex].word;
    this->selectedWordHint = randomWordsLibrary[randomIndex].hint;
    this->selectedWordLength = this->selectedWord.length();
}

string RandomWords::getWord() const { return selectedWord; }
string RandomWords::getWordHint() const { return selectedWordHint; }
int RandomWords::getWordLength() const { return selectedWordLength; }
