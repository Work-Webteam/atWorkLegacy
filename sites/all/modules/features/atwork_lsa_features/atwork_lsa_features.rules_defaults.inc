<?php

/**
 * @file
 * atwork_lsa_features.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function atwork_lsa_features_default_rules_configuration() {
  $items = array();
  $items['rules_lsa_confirmation'] = entity_import('rules_config', '{ "rules_lsa_confirmation" : {
      "LABEL" : "LSA Confirmation",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "TAGS" : [ "long service awards" ],
      "REQUIRES" : [ "rules", "mimemail" ],
      "ON" : { "node_insert--lsa_application" : { "bundle" : "lsa_application" } },
      "DO" : [
        { "mimemail" : {
            "USING" : {
              "key" : "lsa_application_notification",
              "to" : "[node:field-lsa-email]",
              "subject" : "Your Long Service Award Application has been received",
              "body" : "\\u003Cspan style=\\u0022background:yellow\\u0022\\u003ETHIS IS AN AUTOMATED EMAIL. NO RESPONSE IS REQUIRED.\\u003C\\/span\\u003E\\r\\n\\r\\n\\r\\nThank you for using the Long Service Awards e-registration system.\\r\\n\\r\\nThe Office of Protocol will be mailing your formal invitations to Long Service Award registrants starting in \\u003Cstrong\\u003Emid June\\u003C\\/strong\\u003E.  The RSVP date on the invitations will be \\u003Cstrong\\u003EJuly 31, 2014\\u003C\\/strong\\u003E.  If you do not receive an invitation by the end of July, please contact the Office of Protocol in Victoria at (250) 356-7916.  \\r\\n\\r\\nThe 2014 Long Service Award Ceremonies will be held at Government House in Victoria, during the months of September and October.  The particular night for your ministry or organization\\u0027s ceremony will be specified on your invitation.  Please note, because these ceremonies are tailored to address specific ministries and organizations, it will not possible to switch your ceremony night with another.\\r\\n\\r\\nIf you have registered but find you\\u2019re unable to attend the ceremonies this fall, you will be given a one-year\\u2019s grace period to register for this specific milestone in 2015, in order to attend the dinner and ceremonies at Government House.  Arrangements will be made to have your 2014 service award presented to you at your place of work, sometime following the final ceremony in November.\\r\\n\\r\\nAn automated email has been sent to your supervisor so that he or she is aware of your eligibility for a Long Service Award and can provide you with the necessary supports, such as time off and travel coverage (if applicable). \\r\\n\\r\\nFor general inquiries, please contact your Ministry Long Service Award Contact:  https:\\/\\/gww.gov.bc.ca\\/career\\/long-service-awards\\/contacts\\r\\n\\r\\nFor more information about the Long Service Awards Program, please visit the web site via @Work:  https:\\/\\/gww.gov.bc.ca\\/career\\/long-service-awards\\r\\n\\r\\nCongratulations on your pending award!\\r\\n\\r\\n\\r\\n\\u003Cem\\u003EThe personal information requested is collected under the authority of and used for the purpose of administering the \\u003Ca href=\\u0022http:\\/\\/www.bclaws.ca\\/EPLibraries\\/bclaws_new\\/document\\/LOC\\/freeside\\/--%20p%20--\\/public%20service%20act%20rsbc%201996%20c.%20385\\/00_96385_01.xml\\u0022\\u003EPublic Service Act\\u003C\\/a\\u003E.  All information provided to us will be considered as supplied in confidence.\\r\\n\\r\\nUnder certain circumstances some information may be released subject to the provisions of the \\u003Ca href=\\u0022http:\\/\\/www.bclaws.ca\\/EPLibraries\\/bclaws_new\\/document\\/ID\\/freeside\\/96165_00\\u0022\\u003EFreedom of Information and Protection of Privacy Act\\u003C\\/a\\u003E.  If you have any questions about the collection and use of this information, please contact the Office of Protocol at (250) 356-7916, PO Box 9422 Stn. Prov. Govt., Victoria BC V8W 9V1.  This information will be kept for a minimum of one year.\\u003C\\/em\\u003E\\r\\n"
            },
            "PROVIDE" : { "send_status" : { "send_status" : "Send status" } }
          }
        },
        { "mimemail" : {
            "USING" : {
              "key" : "lsa_supervisor_notification",
              "to" : "[node:field-lsa-supervisor-email]",
              "subject" : "An employee you supervise has applied for a Long Service Award",
              "body" : "\\u003Cspan style=\\u0022background:yellow\\u0022\\u003ETHIS IS AN AUTOMATED EMAIL. NO RESPONSE IS REQUIRED.\\u003C\\/span\\u003E\\r\\n\\r\\nThis note is to advise you that [node:title], who you supervise, has registered to receive a [node:field-lsa-years-of-service] year Long Service Award later this year.\\r\\n\\r\\nEligible employees are any full-time, part-time or seasonal staff who will reach their 25th, 30th, 35th, 40th, or 45th anniversary with the BC Public Service by December 31, 2014, or who have achieved one of these milestones but not previously been recognized for it.\\r\\n\\r\\nThe Office of Protocol will be mailing formal invitations to Long Service Award registrants starting in June.  The 2014 Long Service Award Ceremonies will be held at Government House in Victoria between \\u003Cstrong\\u003Elate September and October\\u003C\\/strong\\u003E. The invitations will specify the particular night for your ministry or organization\\u0027s ceremony.\\r\\n\\r\\nLong Service Award recipients from outside Greater Victoria are considered to be on travel status and are to be granted time off as applicable to attend their Long Service Award Ceremony.  The ministry or organization is responsible for all travel-related costs to and from the ceremony, for both the recipient and their guest.  \\r\\n\\r\\nAlthough Victoria-based recipients do not need to travel to attend the Long Service Awards dinner, they must be provided a reasonable amount of time to prepare for the ministry specific pre-ceremony reception (if applicable), as well as the gala dinner event. Therefore, it is recommended that recipients leave their workplace by 2:00 p.m. on the day of their event, without any negative impact on their pay. In cases where the recipient is a front-line worker, arrangements for coverage should be made in advance, as prior notice of the ceremony date will be available one month in advance.\\r\\n\\r\\nAs alcohol will be served at the ceremony, taxi expenses will be paid by the employee\\u0027s ministry or organization for their Victoria-based staff to attend the event and to travel home once the event is over.\\r\\n\\r\\n  \\r\\nFor more information about the Long Service Awards Program, including information about eligibility criteria and\\/or policies that support this program, please visit: https:\\/\\/gww.gov.bc.ca\\/career\\/long-service-awards\\r\\n \\r\\nIf you have questions, please contact your Ministry Long Service Awards Contact: https:\\/\\/gww.gov.bc.ca\\/career\\/long-service-awards\\/contacts\\r\\n"
            },
            "PROVIDE" : { "send_status" : { "send_status" : "Send status" } }
          }
        }
      ]
    }
  }');
  return $items;
}
