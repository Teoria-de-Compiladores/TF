
// Generated from src/AudioScore.g4 by ANTLR 4.13.1


#include "AudioScoreListener.h"
#include "AudioScoreVisitor.h"

#include "AudioScoreParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct AudioScoreParserStaticData final {
  AudioScoreParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  AudioScoreParserStaticData(const AudioScoreParserStaticData&) = delete;
  AudioScoreParserStaticData(AudioScoreParserStaticData&&) = delete;
  AudioScoreParserStaticData& operator=(const AudioScoreParserStaticData&) = delete;
  AudioScoreParserStaticData& operator=(AudioScoreParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag audioscoreParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
AudioScoreParserStaticData *audioscoreParserStaticData = nullptr;

void audioscoreParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (audioscoreParserStaticData != nullptr) {
    return;
  }
#else
  assert(audioscoreParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<AudioScoreParserStaticData>(
    std::vector<std::string>{
      "program", "tempoDecl", "statement", "noteStmt", "restStmt"
    },
    std::vector<std::string>{
      "", "'tempo'", "';'", "'rest'"
    },
    std::vector<std::string>{
      "", "", "", "", "NOTE", "OCTAVE", "DUR", "INT", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,8,41,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,1,0,3,0,12,8,0,1,0,5,
  	0,15,8,0,10,0,12,0,18,9,0,1,0,1,0,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,
  	1,2,3,2,32,8,2,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,0,0,5,0,2,4,6,8,0,0,38,
  	0,11,1,0,0,0,2,21,1,0,0,0,4,31,1,0,0,0,6,33,1,0,0,0,8,37,1,0,0,0,10,12,
  	3,2,1,0,11,10,1,0,0,0,11,12,1,0,0,0,12,16,1,0,0,0,13,15,3,4,2,0,14,13,
  	1,0,0,0,15,18,1,0,0,0,16,14,1,0,0,0,16,17,1,0,0,0,17,19,1,0,0,0,18,16,
  	1,0,0,0,19,20,5,0,0,1,20,1,1,0,0,0,21,22,5,1,0,0,22,23,5,7,0,0,23,24,
  	5,2,0,0,24,3,1,0,0,0,25,26,3,6,3,0,26,27,5,2,0,0,27,32,1,0,0,0,28,29,
  	3,8,4,0,29,30,5,2,0,0,30,32,1,0,0,0,31,25,1,0,0,0,31,28,1,0,0,0,32,5,
  	1,0,0,0,33,34,5,4,0,0,34,35,5,5,0,0,35,36,5,6,0,0,36,7,1,0,0,0,37,38,
  	5,3,0,0,38,39,5,6,0,0,39,9,1,0,0,0,3,11,16,31
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  audioscoreParserStaticData = staticData.release();
}

}

AudioScoreParser::AudioScoreParser(TokenStream *input) : AudioScoreParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

AudioScoreParser::AudioScoreParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  AudioScoreParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *audioscoreParserStaticData->atn, audioscoreParserStaticData->decisionToDFA, audioscoreParserStaticData->sharedContextCache, options);
}

AudioScoreParser::~AudioScoreParser() {
  delete _interpreter;
}

const atn::ATN& AudioScoreParser::getATN() const {
  return *audioscoreParserStaticData->atn;
}

std::string AudioScoreParser::getGrammarFileName() const {
  return "AudioScore.g4";
}

const std::vector<std::string>& AudioScoreParser::getRuleNames() const {
  return audioscoreParserStaticData->ruleNames;
}

const dfa::Vocabulary& AudioScoreParser::getVocabulary() const {
  return audioscoreParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView AudioScoreParser::getSerializedATN() const {
  return audioscoreParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

AudioScoreParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AudioScoreParser::ProgramContext::EOF() {
  return getToken(AudioScoreParser::EOF, 0);
}

AudioScoreParser::TempoDeclContext* AudioScoreParser::ProgramContext::tempoDecl() {
  return getRuleContext<AudioScoreParser::TempoDeclContext>(0);
}

std::vector<AudioScoreParser::StatementContext *> AudioScoreParser::ProgramContext::statement() {
  return getRuleContexts<AudioScoreParser::StatementContext>();
}

AudioScoreParser::StatementContext* AudioScoreParser::ProgramContext::statement(size_t i) {
  return getRuleContext<AudioScoreParser::StatementContext>(i);
}


size_t AudioScoreParser::ProgramContext::getRuleIndex() const {
  return AudioScoreParser::RuleProgram;
}

void AudioScoreParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AudioScoreListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void AudioScoreParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AudioScoreListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


std::any AudioScoreParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AudioScoreVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

AudioScoreParser::ProgramContext* AudioScoreParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, AudioScoreParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(11);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AudioScoreParser::T__0) {
      setState(10);
      tempoDecl();
    }
    setState(16);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AudioScoreParser::T__2

    || _la == AudioScoreParser::NOTE) {
      setState(13);
      statement();
      setState(18);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(19);
    match(AudioScoreParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TempoDeclContext ------------------------------------------------------------------

AudioScoreParser::TempoDeclContext::TempoDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AudioScoreParser::TempoDeclContext::INT() {
  return getToken(AudioScoreParser::INT, 0);
}


size_t AudioScoreParser::TempoDeclContext::getRuleIndex() const {
  return AudioScoreParser::RuleTempoDecl;
}

void AudioScoreParser::TempoDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AudioScoreListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTempoDecl(this);
}

void AudioScoreParser::TempoDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AudioScoreListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTempoDecl(this);
}


std::any AudioScoreParser::TempoDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AudioScoreVisitor*>(visitor))
    return parserVisitor->visitTempoDecl(this);
  else
    return visitor->visitChildren(this);
}

AudioScoreParser::TempoDeclContext* AudioScoreParser::tempoDecl() {
  TempoDeclContext *_localctx = _tracker.createInstance<TempoDeclContext>(_ctx, getState());
  enterRule(_localctx, 2, AudioScoreParser::RuleTempoDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(21);
    match(AudioScoreParser::T__0);
    setState(22);
    match(AudioScoreParser::INT);
    setState(23);
    match(AudioScoreParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

AudioScoreParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AudioScoreParser::NoteStmtContext* AudioScoreParser::StatementContext::noteStmt() {
  return getRuleContext<AudioScoreParser::NoteStmtContext>(0);
}

AudioScoreParser::RestStmtContext* AudioScoreParser::StatementContext::restStmt() {
  return getRuleContext<AudioScoreParser::RestStmtContext>(0);
}


size_t AudioScoreParser::StatementContext::getRuleIndex() const {
  return AudioScoreParser::RuleStatement;
}

void AudioScoreParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AudioScoreListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void AudioScoreParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AudioScoreListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


std::any AudioScoreParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AudioScoreVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

AudioScoreParser::StatementContext* AudioScoreParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 4, AudioScoreParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(31);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AudioScoreParser::NOTE: {
        enterOuterAlt(_localctx, 1);
        setState(25);
        noteStmt();
        setState(26);
        match(AudioScoreParser::T__1);
        break;
      }

      case AudioScoreParser::T__2: {
        enterOuterAlt(_localctx, 2);
        setState(28);
        restStmt();
        setState(29);
        match(AudioScoreParser::T__1);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NoteStmtContext ------------------------------------------------------------------

AudioScoreParser::NoteStmtContext::NoteStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AudioScoreParser::NoteStmtContext::NOTE() {
  return getToken(AudioScoreParser::NOTE, 0);
}

tree::TerminalNode* AudioScoreParser::NoteStmtContext::OCTAVE() {
  return getToken(AudioScoreParser::OCTAVE, 0);
}

tree::TerminalNode* AudioScoreParser::NoteStmtContext::DUR() {
  return getToken(AudioScoreParser::DUR, 0);
}


size_t AudioScoreParser::NoteStmtContext::getRuleIndex() const {
  return AudioScoreParser::RuleNoteStmt;
}

void AudioScoreParser::NoteStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AudioScoreListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNoteStmt(this);
}

void AudioScoreParser::NoteStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AudioScoreListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNoteStmt(this);
}


std::any AudioScoreParser::NoteStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AudioScoreVisitor*>(visitor))
    return parserVisitor->visitNoteStmt(this);
  else
    return visitor->visitChildren(this);
}

AudioScoreParser::NoteStmtContext* AudioScoreParser::noteStmt() {
  NoteStmtContext *_localctx = _tracker.createInstance<NoteStmtContext>(_ctx, getState());
  enterRule(_localctx, 6, AudioScoreParser::RuleNoteStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(33);
    match(AudioScoreParser::NOTE);
    setState(34);
    match(AudioScoreParser::OCTAVE);
    setState(35);
    match(AudioScoreParser::DUR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RestStmtContext ------------------------------------------------------------------

AudioScoreParser::RestStmtContext::RestStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AudioScoreParser::RestStmtContext::DUR() {
  return getToken(AudioScoreParser::DUR, 0);
}


size_t AudioScoreParser::RestStmtContext::getRuleIndex() const {
  return AudioScoreParser::RuleRestStmt;
}

void AudioScoreParser::RestStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AudioScoreListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRestStmt(this);
}

void AudioScoreParser::RestStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AudioScoreListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRestStmt(this);
}


std::any AudioScoreParser::RestStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AudioScoreVisitor*>(visitor))
    return parserVisitor->visitRestStmt(this);
  else
    return visitor->visitChildren(this);
}

AudioScoreParser::RestStmtContext* AudioScoreParser::restStmt() {
  RestStmtContext *_localctx = _tracker.createInstance<RestStmtContext>(_ctx, getState());
  enterRule(_localctx, 8, AudioScoreParser::RuleRestStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(37);
    match(AudioScoreParser::T__2);
    setState(38);
    match(AudioScoreParser::DUR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void AudioScoreParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  audioscoreParserInitialize();
#else
  ::antlr4::internal::call_once(audioscoreParserOnceFlag, audioscoreParserInitialize);
#endif
}
