class user:
    def __init__(self):
        self.handle = ""
        self.email = ""
        self.vkId = ""
        self.openId =""
        self.firstName=""
        self.lastName=""
        self.country=""
        self.city=""
        self.organization=""
        self.contribution=0
        self.rank=""
        self.rating=0
        self.maxRank=""
        self.maxRating=0
        self.lastOnlineTimeSeconds=0
        self.registrationTimeSeconds=0
        self.friendOfCount=0
        self.avatar=""
        self.titlePhoto=""

class blog:
    def __init__(self):
        self.id=0
        self.originalLocale=0
        self.creationTimeSeconds=0
        self.authorHandle=""
        self.title=""
        self.content=""
        self.locale=""
        self.modificationTimeSeconds=0
        self.allowViewHistory = False
        self.tags = []
        self.rating = 0


class comment:
    def __init__(self):
        self.id = 0
        self.creationtime=0
        self.commentorhandle= ''
        self.locale = ""
        self.text = ""
        self.parentCommentId=0
        self.rating = 0

class recentAction:
    def __init__(self):
        self.timeSeconds = 0
        self.blogentry = blog()
        self.comment = comment()

class ratingChange:
    def __init__(self):
        self.contestId=0
        self.contestname=""
        self.handle=""
        self.rank=""
        self.ratingUpdateTimeSeconds=0
        self.oldRating = 0
        self.newRating = 0

class contest:
    def __init__(self):
        self.preparedBy = ""
        self.id=0
        self.name = ""
        self.locale = ""
        self.type=""
        self.phase=""
        self.frozen=False
        self.durationSeconds=0
        self.startTimeSeconds=0
        self.relativeTimeSeconds=0
        self.relativeTimeSeconds=""
        self.websiteUrl=""
        self.description=""
        self.difficulty=0
        self.kind=0
        self.icpcRegion=""
        self.country=""
        self.city=""
        self.season=""

class party:
    #TODO
    pass

class problem:
    #TODO
    pass

class problemStatistics:
    #TODO
    pass
class submission:
    #TODO
    pass
class hack:
    #TODO
    pass
class RanklistRow:
    #TODO
    pass

class member:
    def __init__(self):
        self.handle = ""
        self.name = ""

class problemResult:
    def __init__(self):
        self.point=0
        self.penalty = 0
        self.rejectedAttemptCount=0
        self.type = ""
        self.bestSubmissionTimeSeconds


def to_comment(x):
    asw = comment()
    try:
        asw.parentCommentId = x["parentCommentId"]
    except:
        pass
    try:
        asw.commentorhandle = x["commentatorHandle"]
    except:
        pass
    try:
        asw.id = x["id"]
    except:
        pass
    try:
        asw.creationtime = x["creationTimeSeconds"]
    except:
        pass
    try:
        asw.creationtime = x["rating"]
    except:
        pass 
    try:
        asw.text = x["text"]
    except:
        pass
    try:
        asw.locale = x["locale"]
    except:
        pass
    return asw

def to_contest(x):
    asw = contest()
    try:
        asw.id = x["id"]
    except:
        pass
    try:
        asw.name = x["name"]
    except:
        pass
    try:
        asw.type = x["type"]
    except:
        pass
    try:
        asw.phase = x["phase"]
    except:
        pass
    try:
        asw.frozen = x["frozen"]
    except:
        pass
    try:
        asw.durationSeconds=x["durationSeconds"]
    except:
        pass
    try:
        asw.startTimeSeconds=x["startTimeSeconds"]
    except:
        pass
    try:
        asw.preparedBy=x["preparedBy"]
    except:
        pass
    try:
        asw.websiteUrl=x["websiteUrl"]
    except:
        pass
    try:
        asw.difficulty=x["difficulty"]
    except:
        pass
    try:
        asw.kind=x["kind"]
    except:
        pass
    try:
        asw.icpcRegion=x["icpcRegion"]
    except:
        pass
    try:
        asw.country=x["country"]
    except:
        pass
    try:
        asw.city=x["city"]
    except:
        pass
    try:
        asw.season=x["season"]
    except:
        pass
    return asw

def toblog(x):
    asw = blog()
    try:
        asw.id = x["id"]
    except:
        pass
    try:
        asw.originalLocale = x["originalLocale"]
    except:
        pass
    try:
        asw.allowViewHistory = x["allowViewHistory"]
    except:
        pass
    try:
        asw.creationTimeSeconds = x["creationTimeSeconds"]
    except:
        pass
    try:
        asw.authorHandle = x["authorHandle"]
    except:
        pass
    try:
        asw.title = x["title"]
    except:
        pass
    try:
        asw.content=x["content"]
    except:
        pass
    try:
        asw.locale = x["locale"]
    except:
        pass
    try:
        asw.modificationTimeSeconds = x["modificationTimeSeconds"]
    except:
        pass
    try:
        asw.tags = x["tags"]
    except:
        pass
    try:
        asw.rating = x["rating"]
    except:
        pass
    return asw

def to_recentaction(x):
    asw = recentAction()
    try:
        asw.timeSeconds = x["timeSeconds"]
    except:
        pass
    try:
        asw.blogentry = toblog(x["blogEntry"])
    except:
        pass
    try:
        asw.comment = to_comment(x["comment"])
    except:
        pass
    return asw